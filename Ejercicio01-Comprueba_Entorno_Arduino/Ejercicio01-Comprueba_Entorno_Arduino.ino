#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define PIN_LDR A1
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 or 0x3F, it depends, for a 16 chars and 2 line display
void setup() {
  //Inicializo puerto serie
  Serial.begin(9600);
   Serial.println(F("Inicializando pantalla..."));
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();

}
void loop() {
 int maximo = 0;
  int minimo = 1023;
  Serial.println(A1);
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);
   int sensorValue = analogRead(PIN_LDR);
    maximo = max(maximo, sensorValue);
    minimo = min(minimo, sensorValue);
    Serial.print(sensorValue);
    Serial.print(",");
    Serial.print(maximo);
    Serial.print(",");
    Serial.println(minimo);
    lcd.print(sensorValue);
    lcd.print(",");
    lcd.print(maximo);
    lcd.print(",");
    lcd.print(minimo);
    delay(500);
  
  }
