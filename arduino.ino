#include <SoftwareSerial.h> 
#include <ArduinoJson.h> 
SoftwareSerial nodemcu(5,6);
// 5=Rx 6 =Tx
String str;
void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Program Started");
  nodemcu.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
}
void loop() {
  int a=digitalRead(7),b=digitalRead(8);
  int c=digitalRead(9),d=digitalRead(10);
  int e=digitalRead(11),f=digitalRead(12);
  Serial.print("IR 1:");
  Serial.print(a);
  Serial.print(" IR 2:");
  Serial.println(b);
    Serial.print("IR 3:");
  Serial.print(c);
  Serial.print(" IR 4:");
  Serial.println(d);
    Serial.print("IR 5:");
  Serial.print(e);
  Serial.print(" IR 6:");
  Serial.println(f);
  StaticJsonBuffer<1000> jsonBuffer; 
  JsonObject& data = jsonBuffer.createObject();
  data["IR1"]=a;
  data["IR2"]=b;
   data["IR3"]=c;
  data["IR4"]=d;
   data["IR5"]=e;
  data["IR6"]=f;
  data.printTo(nodemcu);
  jsonBuffer.clear();
  Serial.println("Data Sent!");
  delay(1000);
}
