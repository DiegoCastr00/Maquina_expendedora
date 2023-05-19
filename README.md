# Maquina_expendedora
Proteus: 
  https://drive.google.com/file/d/1YsQXFXn_EKDF0qSPvtO2T6l0bxHRRn8W/view?usp=sharing

Librerias para arduino en proteus: 
  https://youtu.be/kWjPiFNrXMc
  



------  LCD IDC ------- 

Libreria de lcd: https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c


+ SCL(primero) -> 21

+ SDA(segundo)-> 20



#include <Wire.h> 

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x3F, 16, 2);

