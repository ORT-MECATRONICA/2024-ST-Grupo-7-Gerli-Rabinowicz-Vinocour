#include <U8g2lib.h>

#define RELE 18
#define LED 25

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void printBMP_OLED(void);

void setup() {
  Serial.begin(9600);
  Serial.println(F("OLED test"));
  u8g2.begin();
  pinMode(RELE, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  printBMP_OLED();

}

void printBMP_OLED(void) {
  u8g2.clearBuffer();  // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB12_tr);   // choose a suitable font
  u8g2.drawStr(5, 15, "Hola Mundo!");  // write something to the internal memory
  u8g2.sendBuffer();
}