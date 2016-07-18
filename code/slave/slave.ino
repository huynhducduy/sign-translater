#include <SoftwareSerial.h>
 
#define TX_PIN      2
#define RX_PIN      3

const int flexPin = A0;
const int flexPin1 = A1;
const int flexPin2 = A2;
const int flexPin3 = A3;
const int flexPin4 = A7;

int disturTerm = 30;

int value,value1,value2,value3,value4;
 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
 
void setup() {

  Serial.begin(38400);
  while (!Serial) {}
  
  bluetooth.begin(38400);
  while (!bluetooth) {}
  
  Serial.println("Go!");
}

int signes[33][5] = {
  {300,280,190,310,310}, // fuckyou
  {160,270,200,310,140}, // ahihi
  {160,270,280,300,300}, // a
//  {240,230,270,270,230}, // a2
//  {240,230,270,270,230}, // a3
  {300,100,200,120,120}, // b
  {240,230,270,290,250}, // c
  {200,125,280,300,310}, // d
  {300,250,280,300,310}, // d2
  {290,300,280,300,300}, // e
//  {240,230,270,270,230}, // e2
  {270,125,290,300,310}, // g
  {280,110,210,310,320}, // h
  {300,300,300,300,150}, // i
  {160,110,210,310,320}, // k
  {140,140,280,300,310}, // l
  {300,120,200,110,280}, // m
  {300,130,180,310,280}, // n
  {270,260,270,300,210}, // o
//  {240,230,270,270,230}, // o2
//  {240,230,270,270,230}, // o3
  {170,110,270,300,250}, // p
  {210,170,300,300,300}, // q
  {190,100,200,300,270}, // r
  {170,230,290,310,270}, // s
  {280,270,220,170,120}, // t
  {0,0,0,0,0}, // u
//  {240,230,270,270,230}, // u2
  {0,0,0,0,0}, // v
  {170,230,290,310,270}, // x
  {160,280,290,310,160}, // y
};

char* values[]={
  "fuckyou",
  "ahihi",
  "a",
//  "a2",
//  "a3",
  "b",
  "c",
  "d",
  "d2",
  "e",
//  "e2",
  "g",
  "h",
  "i",
  "k",
  "l",
  "m",
  "n",
  "o",
//  "o2",
//  "o3",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
//  "u2",
  "v",
  "x",
  "y"
};

char* test() {
  int i;

  Serial.print(value);
  Serial.print(" ");
  Serial.print(value1);
  Serial.print(" ");
  Serial.print(value2);
  Serial.print(" ");
  Serial.print(value3);
  Serial.print(" ");
  Serial.println(value4);

  char* kek;
  for (i = 0; i < 30; i++){
    if (((value+disturTerm) >=signes[i][0])
    and ((value-disturTerm) <=signes[i][0])
    and ((value1+disturTerm) >=signes[i][1])
    and ((value1-disturTerm) <=signes[i][1])
    and ((value2+disturTerm) >=signes[i][2])
    and ((value2-disturTerm) <=signes[i][2])
    and ((value3+disturTerm) >=signes[i][3])
    and ((value3-disturTerm) <=signes[i][3])
    and ((value4+disturTerm) >=signes[i][4])
    and ((value4-disturTerm) <=signes[i][4])) {
      return values[i];
    }
  }

  return "false";
}
 
void loop() {

  value = analogRead(flexPin);
  value = map(value, 700, 900, 0, 255);
  value1 = analogRead(flexPin1);
  value1 = map(value1, 700, 900, 0, 255);
  value2 = analogRead(flexPin2);
  value2 = map(value2, 700, 900, 0, 255);
  value3 = analogRead(flexPin3);
  value3 = map(value3, 700, 900, 0, 255);
  value4 = analogRead(flexPin4);
  value4 = map(value4, 700, 900, 0, 255);

//  char filename[100] = "";
//
//  boolean test = false;
//
//  unsigned int i = 0;
//
//  while (Serial.available()) {
//    test = true;
//    filename[i] = Serial.read();
//    i++;
//  }

  char* lol = test();
  Serial.println(lol);
  if (lol != "false") {
    bluetooth.write(lol);
    bluetooth.write("#");
  }
  delay(1000);
}


