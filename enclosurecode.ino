//pins
int sensorPin = A1;
int buzzer = 11;
int redLED = 2;
int counter1  = 0;
int counter2 = 0;

//LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

void setup() 
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  lcd.init();

  tone(buzzer,1000);
  delay(200);
  noTone(buzzer);
  delay(100);
  
  tone(buzzer,1000);
  delay(200);
  noTone(buzzer);
  delay(100);
}

void loop() 
{
  //TMP code
     float reading = analogRead(sensorPin);  
     float voltage = (reading * 5.0)/1023.0;
     
     Serial.print(voltage); Serial.println(" volts");
     
     float temperatureC = (voltage - 0.5) * 100; 
     float temperatureF = (temperatureC * 1.8) + 32.0;

     Serial.print(temperatureC); Serial.println(" degrees C");
     Serial.print(temperatureF); Serial.println(" degrees F");

  //lcd
    lcd.backlight();
    
    lcd.setCursor(0,0);
    lcd.print("Temp:");
    
    lcd.setCursor(0,1);
    lcd.print(temperatureF);
    lcd.setCursor(5,1);
    lcd.print("F");  

    lcd.setCursor(7,1);
    lcd.print(temperatureC);
    lcd.setCursor(12,1);
    lcd.print("C");  
    
  //buzzer && LED
    if(temperatureF > 75 || temperatureF < 65)
    {
      counter1++;
      counter2++;
      digitalWrite(redLED,HIGH);
      tone(buzzer,1000);
      delay(800);
      noTone(buzzer);
      digitalWrite(redLED,LOW);
      delay(200);
    }
    else
    {
      delay(1000);
      counter2++;
    }
}
