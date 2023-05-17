#include <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include <Stepper.h>

LiquidCrystal_I2C lcd (0x3F, 16, 2);

Stepper motor1(2048, 2, 4, 3, 5);
Stepper motor2(2048, 6, 8, 7, 9);
Stepper motor3(2048, 10,12,11,13);

const int moneda1 = A0;  
const int moneda2 = A1;                         
const int moneda5 = A2; 
const int moneda10= A3;

int producto1= A4;
int producto2= A5;
int producto3= A6;

int expulsar = A9;

int Motor1= A12;
int Motor2= A13;
int Motor3= A14;

int moneda1_state = 0;
int moneda2_state = 0;
int moneda5_state = 0;
int moneda10_state = 0;

int count =0;
int prestate =0;



void setup() {

  pinMode(moneda1, INPUT_PULLUP);
  pinMode(moneda2, INPUT_PULLUP);
  pinMode(moneda5, INPUT_PULLUP);
  pinMode(moneda10, INPUT_PULLUP);
  
  pinMode(expulsar, INPUT_PULLUP); 
  pinMode(producto1, INPUT_PULLUP);
  pinMode(producto2, INPUT_PULLUP);
  pinMode(producto3, INPUT_PULLUP);
 

  motor1.setSpeed(10);   	
  motor2.setSpeed(10); 
  motor3.setSpeed(10); 

  Wire.begin();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);

}

void loop() {

  moneda1_state = digitalRead(moneda1);
  moneda2_state = digitalRead(moneda2);
  moneda5_state = digitalRead(moneda5);
  moneda10_state= digitalRead(moneda10);

  if(digitalRead(expulsar)==0){
    delay(200);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("expulsar dinero");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dinero expulsado");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1500);
    count = 0;
    
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);

  }
  
if(digitalRead(producto1)==0) {
        delay(200);
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("Preparando:");
        lcd.setCursor(4,1);
        lcd.print("My Motto");
        delay(1600);
        lcd.clear();
        if(count >= 10){
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("Aguarde un");
            lcd.setCursor(5,1);
            lcd.print("momento");

                motor1.step(2048);			// envia comando para dar la cantidad de pasos
                digitalWrite(2, LOW); 		// desenergiza todas las bobinas
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);


            lcd.clear();
            lcd.setCursor(1,0);
            lcd.print("Producto listo");
            delay(1500);
            lcd.clear();
            lcd.setCursor(5,0);
            lcd.print("cambio: ");
            count = count - 10;
            lcd.setCursor(7,1);
            lcd.print(count);
            delay(1700);
            lcd.clear();
            
            count = 0;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ingrese monedas");
            lcd.setCursor(0,1);
            lcd.print("> ");
            lcd.print(count);
          } else {
                lcd.clear();
                    lcd.setCursor(3,0);
                    lcd.print("No alcanza");
                    delay(1500);
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("ingrese monedas");
                    lcd.setCursor(0,1);
                    lcd.print("> ");
                    lcd.print(count);
          } 
        }
          {
            if(digitalRead(producto2)==0){
              delay(200);
              lcd.clear();
              lcd.setCursor(3,0);
              lcd.print("Preparando:");
              lcd.setCursor(2,1);
              lcd.print("Chicles Fresa");
              delay(1600);
              lcd.clear();
                if(count >= 8){
                  lcd.setCursor(3,0);
                  lcd.print("Aguarde un");
                  lcd.setCursor(5,1);
                  lcd.print("momento");

                    motor2.step(2048);			// envia comando para dar la cantidad de pasos
                    digitalWrite(6, LOW); 		// desenergiza todas las bobinas
                    digitalWrite(7, LOW);
                    digitalWrite(8, LOW);
                    digitalWrite(9, LOW);

                    lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("Producto listo");
                    delay(1500);
                    lcd.clear();
                    lcd.setCursor(5,0);
                    lcd.print("cambio: ");
                    count = count - 8;
                    lcd.setCursor(7,1);
                    lcd.print(count);
                    
                    delay(1700);
                    lcd.clear();
                    count = 0;
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("ingrese monedas");
                    lcd.setCursor(0,1);
                    lcd.print("> ");
                    lcd.print(count);
                  } else {
                        lcd.clear();
                        lcd.setCursor(3,0);
                        lcd.print("No alcanza");
                        delay(1500);
                        lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("ingrese monedas");
                        lcd.setCursor(0,1);
                        lcd.print("> ");
                        lcd.print(count);
                  } 
                }
            }
           {
              if(digitalRead(producto3)==0){
                delay(200);
                lcd.clear();
                lcd.setCursor(3,0);
                lcd.print("Preparando:");
                lcd.setCursor(7,1);
                lcd.print("UVA");
                delay(1600);
                lcd.clear();
                if(count >= 15){
                  lcd.setCursor(3,0);
                  lcd.print("Aguarde un");
                  lcd.setCursor(5,1);
                  lcd.print("momento");

                    motor3.step(2048);			// envia comando para dar la cantidad de pasos
                    digitalWrite(10, LOW); 		// desenergiza todas las bobinas
                    digitalWrite(11, LOW);
                    digitalWrite(12, LOW);
                    digitalWrite(13, LOW);

                  lcd.setCursor(1,0);
                  lcd.print("Producto listo");
                  delay(1500);
                  lcd.clear();
                  lcd.setCursor(5,0);
                  lcd.print("cambio: ");
                  count = count - 15;
                  lcd.setCursor(7,1);
                  lcd.print(count);
                  delay(1700);
                  lcd.clear();
                  
                  count = 0;
                   lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("ingrese monedas");
                  lcd.setCursor(0,1);
                  lcd.print("> ");
                  lcd.print(count);

                } else {
                    lcd.clear();
                    lcd.setCursor(3,0);
                    lcd.print("No alcanza");
                    delay(1500);
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("ingrese monedas");
                    lcd.setCursor(0,1);
                    lcd.print("> ");
                    lcd.print(count);
                    

                    } 
               }
             }

  if (moneda1_state == 0 && prestate == 0) {
    delay(200);
    count++;  
    lcd.clear();
    lcd.setCursor(0,0);
   lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);
  lcd.print(" ");
    prestate = 1;
  }
// Moneda de valor 2
   if (moneda2_state == 0 && prestate == 0) {
     delay(200);
    count=count+2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);
  lcd.print(" ");
   prestate = 1;
  } 
// Moneda de valor 5
  if (moneda5_state == 0 && prestate == 0) {
    delay(200);
    count=count+5;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);
  lcd.print(" ");
   prestate = 1;
  } 
// Moneda de valor 10
  if (moneda10_state == 0 && prestate == 0) {
    delay(200);
    count=count+10;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);
  lcd.print(" ");
   prestate = 1;
  } 
 else if(moneda1_state == 1 && moneda2_state == 1 && moneda5_state == 1 && moneda10_state == 1) {
    prestate = 0;
  }

  }