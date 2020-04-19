/*
 * HelTec Automation(TM) ESP32 Series Dev boards OLED Drawing Function test code
 *
 * - Some OLED Drawing Function function test;
 *
 * by lxyzn from HelTec AutoMation, ChengDu, China
 * 
 * www.heltec.cn
 *
 * this project also realess in GitHub:
 * https://github.com/HelTecAutomation/Heltec_ESP32
*/


// This example just provide basic function test;
// For more informations, please vist www.heltec.cn or mail to support@heltec.cn

#include "Arduino.h"
#include "heltec.h"

void printBuffer(void) {
  // Initialize the log buffer
  // allocate memory to store 8 lines of text and 30 chars per line.
  Heltec.display->setLogBuffer(2, 30);

  // Some test data
  const char* test[] = {
      "Hello",
      "World" 
  };

  for (uint8_t i = 0; i < 11; i++) {
    Heltec.display->clear();
    // Print to the screen
    Heltec.display->println(test[i]);
    // Draw it to the internal screen buffer
    Heltec.display->drawLogBuffer(0, 0);
    // Display it on the screen
    Heltec.display->display();
    delay(500);
  }
}

void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Serial Enable*/);
  
  Heltec.display->setContrast(255);

  printBuffer();
  delay(1000);
  Heltec.display->clear();
}

void loop() { }
