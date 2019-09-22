#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <VL53L0X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
#define MM2IN 0.03937007874
#define MAXMM 1219.2



VL53L0X sensor;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
unsigned int px = 0;
int v[SCREEN_WIDTH];

void setup() {
  // clear the array of readings
  for (int n = 0; n < SCREEN_WIDTH; n++)
    v[n] = 0;

  Serial.begin(9600);

  // initialize the ToF sensor in continuous mode
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  // initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // generate display voltage from 3.3v internally?
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.setTextSize(3);
  display.setTextColor(INVERSE);
}

void loop() {
  display.clearDisplay();

  v[px] = sensor.readRangeContinuousMillimeters();

  // draw a line for every measurement
  for (int n = 0; n < SCREEN_WIDTH; n++) {
    double mm = v[(n + px) % SCREEN_WIDTH];
    int height = (int)(SCREEN_HEIGHT * mm / MAXMM);
    constrain(height, 0, SCREEN_HEIGHT);
    display.drawFastVLine(n, 0, height, WHITE);
  } // TODO I should sample faster and display a bounds!

  // print the current distance in inches
  double inches = ((int)(v[px] * MM2IN * 10))/10.0;
  String s = String(inches);//+"\"";
  display.setCursor(15, 15);
  display.print(s);
//  Serial.println(s);

  px = (px + 1) % SCREEN_WIDTH;
  display.display();
  delay(50);
}

//// try an approach where we only update the measurement and a single column everyframe...
  //  display.startscrollright(0x00,0x0f);
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

  // // seed the rng
  // randomSeed(analogRead(0));

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
