#include <U8g2lib.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define RELE 18
#define LED 25
#define DHTPIN 23
#define DHTTYPE DHT11  // DHT 11

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
DHT dht(DHTPIN, DHTTYPE);

void printBMP_OLED(void);

void setup() {
  Serial.begin(9600);

  u8g2.begin();
  dht.begin();

  pinMode(RELE, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  String temp;
  
  printBMP_OLED();

  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  u8g2.clearBuffer();                  // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB12_tr);  // choose a suitable font

  sprintf(temp, "%d", t);  //convierto el valor float a string
  //temp = temp+"°C";
  u8g2.drawStr(15, 15, temp);
  
  u8g2.sendBuffer();
}
