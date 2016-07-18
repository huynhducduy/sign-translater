const int flexPin = A0;
const int flexPin1 = A1;
const int flexPin2 = A2;
const int flexPin3 = A3;
const int flexPin4 = A7;

int value,value1,value2,value3,value4;

void setup(){
  
  Serial.begin(9600);

}

void loop(){
  
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
  Serial.print(value);
  Serial.print(" ");
  Serial.print(value1);
  Serial.print(" ");
  Serial.print(value2);
  Serial.print(" ");
  Serial.print(value3);
  Serial.print(" ");
  Serial.println(value4);
  delay(500);
}
