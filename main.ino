code/main.ino
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int batteryPin = A0;
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {
float temp = dht.readTemperature();
int batteryValue = analogRead(batteryPin);
float batteryVoltage = batteryValue * (5.0 / 1023.0) * 4;
Serial.print("Engine Temperature: ");
Serial.println(temp);
Serial.print("Battery Voltage: ");
if(temp > 80) {
Serial.println("Warning: Engine Overheating!");
}
if(batteryVoltage < 11.0) {
Serial.println("Low Battery Warning!");
}
delay(2000);
}
