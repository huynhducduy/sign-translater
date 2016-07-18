#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>
 
TMRpcm tmrpcm;
unsigned long time = 0;
 
void setup()
{
  tmrpcm.speakerPin = 9;
 
  Serial.begin(9600);

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
  tmrpcm.play("a.wav");
  delay(2000);
  digitalWrite(9, LOW);
}
