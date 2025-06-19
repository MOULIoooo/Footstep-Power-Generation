#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address (0x27 or 0x3F), 16 columns, 2 rows

void setup() {
    Serial.begin(9600);
    lcd.init();    
    lcd.backlight(); 
    lcd.setCursor(0, 0);
    lcd.print("Reading Sensor");
}

void loop() {
    int sensorValue = analogRead(A0);  
    float voltage = sensorValue * (5.0 / 1023.0);  

    lcd.clear();
    
    if(sensorValue>100){
      lcd.setCursor(0, 0);
      lcd.print("Voltage: ");
      lcd.print(voltage, 3);
      lcd.print("mV");
    }else{
      lcd.setCursor(0, 0);
      lcd.print("Voltage: ");
      lcd.print(0, 3);
      lcd.print("mV");
    }
     // 3 decimal places

    Serial.print("Analog Value: ");
    Serial.print(sensorValue);
    Serial.print("  |  Voltage: ");
    Serial.println(voltage, 3);

    delay(2000);
}
