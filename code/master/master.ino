#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <SoftwareSerial.h>
 
#define TX_PIN      2
#define RX_PIN      3

#define SD_ChipSelectPin 4

TMRpcm tmrpcm;

SoftwareSerial bluetooth(RX_PIN, TX_PIN);

void setup()
{
  Serial.begin(38400);
  while (!Serial) {}
  
  bluetooth.begin(38400);
  while (!bluetooth) {}

  tmrpcm.speakerPin = 9;

  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  else {
    Serial.println("OK");
  }

  tmrpcm.play("fuckyou.wav");
  delay(2000);
  digitalWrite(9, LOW);

}

void loop()
{
  unsigned int i = 0;

  char filename[100] = {};

//  while (bluetooth.available()) {
//    test = true;
//    filename[i] = bluetooth.read();
//    i++;
//  }

  bluetooth.readBytesUntil(35,filename,100);
  
  if (strlen(filename) > 0) {
    strcat(filename, ".wav");
    tmrpcm.play(filename);
    Serial.println(filename);
  }
}

