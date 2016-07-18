#include <SoftwareSerial.h>
 
#define TX_PIN      2
#define RX_PIN      3
 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
 
void setup() {

  Serial.begin(38400);
  while (!Serial) {}
  
  bluetooth.begin(38400);
  while (!bluetooth) {}
  
  Serial.println("Go!");
}
 
void loop() {
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}

