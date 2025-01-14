//WS2812，RGB灯环
//炫彩流水灯，第一圈红色，第二圈绿色，第三圈蓝色，第四圈红色，循环显示
/// 目标是改成呼吸灯 + 电机
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include "Adafruit_FreeTouch.h"

#define PIN 10    // 控制灯带的引脚
#define NUM_LEDS 7  // 灯带上灯的数量

Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE); // 触摸实例
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);  // 灯带实例
Servo myservo;

float MaximumBrightness = 255;
float SpeedFactor = 0.005; // I don't actually know what would look good
float StepDelay = 15; // ms for a step delay on the lights
int skills;

void setup() {
  strip.begin();           // 初始化灯带
  strip.show();            // 所有LED灯关闭
    myservo.attach(2); 
    if (! qt_1.begin())  
    Serial.println("Failed to begin qt on pin A0");
}

void loop() {
  skills = random(1, 5);
  Serial.println(skills);
  int counter, result = 0;
  counter = millis();
  result = qt_1.measure(); 
  if((result > 600) && (skills == 1)){  //pink
    pink_up();
    delay(1500);
    pink_down();
    delay(1500);
  }
  if((result > 600) && (skills == 2)){//Red
    red_up();
    delay(1500);
    red_down();
    delay(1500);
  }
  if((result > 600) && (skills == 3)){//green
    green_up();
    delay(1500);
    green_down();
    delay(1500);
  }
  if((result > 600) && (skills == 4)){//blue
    blue_up();
    delay(1500);
    blue_down();
    delay(1500);
  }
  else{
    close_all();
  }
  delay(1500);
}

// 粉色变亮
void pink_up() {
  strip.clear(); 
  for (int i = 0; i < MaximumBrightness; i++) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 255, 0, 255);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 粉色变暗
void pink_down() {
  for (int i = MaximumBrightness; i > 0; i--) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 255, 0, 255);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 蓝色变亮
void blue_up() {
  strip.clear(); 
  for (int i = 0; i < MaximumBrightness; i++) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 0, 255);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 蓝色变暗
void blue_down() {
  for (int i = MaximumBrightness; i > 0; i--) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 0, 255);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 红色变亮
void red_up() {
  strip.clear(); 
  for (int i = 0; i < MaximumBrightness; i++) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 255, 0, 0);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 红色变暗
void red_down() {
  for (int i = MaximumBrightness; i > 0; i--) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 255, 0, 0);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 绿色变亮
void green_up() {
  strip.clear(); 
  for (int i = 0; i < MaximumBrightness; i++) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 255, 0);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 绿色变暗
void green_down() {
  for (int i = MaximumBrightness; i > 0; i--) {
    strip.setBrightness(i);
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 255, 0);
    }
    strip.show();
    delay(StepDelay);
    map(i, 0, 255, 5, 58);
    myservo.write(map(i, 0, 255, 65, 0));
  }
}

// 关闭所有灯，合上花朵
void close_all(){
    myservo.write(65);
    for(int i = 0; i < NUM_LEDS; i++){
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
    strip.show();
}
