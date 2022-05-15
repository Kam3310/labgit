#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 32 //กำหนดขาที่จะเชื่อมต่อ Sensor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 


void setup() {
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library");
  sensors.begin();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(1, 0); 
  lcd.print("Temp");
  lcd.setCursor(0, 1); 
  lcd.print("W:");
  lcd.setCursor(8, 1); 
  lcd.print("T:");
}

void loop() {
  sensors.requestTemperatures(); //อ่านข้อมูลจาก library
  float watertemp = sensors.getTempCByIndex(0); 
  float temp = sensors.getTempCByIndex(1); 
  lcd.setCursor(2, 1); 
  lcd.print(watertemp);
  lcd.setCursor(10, 1); 
  lcd.print(temp);
  delay(250);
}
// by www.myarduino.net
