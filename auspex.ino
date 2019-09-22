#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <VL53L0X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4

VL53L0X sensor;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned int px = 0;
int v[SCREEN_WIDTH];

void setup() {
  Serial.begin(9600);

  // initialize the ToF sensor in continuous mode
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  // clear the array of readings
  for (int n = 0; n < SCREEN_WIDTH; n++)
    v[n] = 0;

  // seed the rng
  randomSeed(analogRead(0));

  // initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // generate display voltage from 3.3v internally?
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.setTextSize(5);
  display.setTextColor(INVERSE);

  // Adafruit splash
  display.display();
  delay(100);

  //  display.startscrollright(0x00,0x0f);
}

void loop() {
  display.clearDisplay();

  //  // simulate a smoothly varying measurement.
  //  vy += (random(5)-3);
  //  if (vy<-4)
  //    vy=0;//-4;
  //  else if (vy>4)
  //    vy=0;//4;
  //
  //  py += vy;
  //  if (py<0)
  //    py = 0;
  //  else if (py>=SCREEN_HEIGHT)
  //    py = SCREEN_HEIGHT-1;
  //  v[px] = py;

  v[px] = sensor.readRangeContinuousMillimeters();
  v[px] /= 10;
  if (v[px] > 64)
    v[px] = 64;

  for (int n = 0; n < SCREEN_WIDTH; n++)
    display.drawFastVLine(n, 0, v[(n + px) % SCREEN_WIDTH], WHITE);

  display.setCursor(15, 15);
  display.print(String(v[px]));

  px = (px + 1) % SCREEN_WIDTH;
  display.display();
  delay(50);
}

//// try an approach where we only update the measurement and a single column everyframe...
//void loop() { // unfortunately I can't really figure out how to update the buffer and scroll it simultaneously...
//
////  px = (px+1) % SCREEN_WIDTH;
//  display.drawFastVLine(px, 0, SCREEN_HEIGHT, BLACK);
//  py = random(0, SCREEN_HEIGHT);
//  display.drawFastVLine(px, 0, py, WHITE);
//
//  // remove old measurement by reapeating text with inverse color
//  // scroll screen horizontally
//  // write new measurement?
//  // optionally we can just see how fast we can draw the whole screen...
//
////  display.display();
//  delay(50);
//}
