#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


const int moneda1 = A0;  
const int moneda2 = A1;                         
const int moneda5 = A2; 
const int moneda10= A3;

int producto1= A4;
int producto2= A5;
int producto3= A6;
int producto4= A7;

int seguir = A8;
int expulsar = A9;

int Motor1= A12;
int Motor2= A13;
int Motor3= A14;
int Motor4= A15;

int moneda1_state = 0;
int moneda2_state = 0;
int moneda5_state = 0;
int moneda10_state = 0;

int count =0;
int prestate =0;
int sig=0;
int reinicio=0;


void setup() {

  pinMode(moneda1, INPUT_PULLUP);
  pinMode(moneda2, INPUT_PULLUP);
  pinMode(moneda5, INPUT_PULLUP);
  pinMode(moneda10, INPUT_PULLUP);
  pinMode(seguir, INPUT_PULLUP); 
  pinMode(expulsar, INPUT_PULLUP); 
  pinMode(producto1, INPUT_PULLUP);
  pinMode(producto2, INPUT_PULLUP);
  pinMode(producto3, INPUT_PULLUP);
  pinMode(producto4, INPUT_PULLUP);

  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);  


  lcd.begin(16, 2);
  lcd.clear();

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
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("expulsar dinero");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dinero expulsado");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(300);
    count = 0;
    
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ingrese monedas");
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count);

  }
  
if(digitalRead(producto1)==0) {
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("Preparando:");
        lcd.setCursor(5,1);
        lcd.print("NARANJA");
        delay(500);
        lcd.clear();
        if(count >= 10){
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("Aguarde un");
            lcd.setCursor(5,1);
            lcd.print("momento");
            digitalWrite (Motor1, HIGH);
            delay(1000);
            digitalWrite (Motor1, LOW);
            lcd.clear();
            lcd.setCursor(1,0);
            lcd.print("Bebida lista");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("cambio: ");
            count = count - 10;
            lcd.setCursor(2,1);
            lcd.print(count);
            delay(1000);
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
                    lcd.setCursor(0,0);
                    lcd.print("No alcanza");
                    delay(250);
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
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("Preparando:");
            lcd.setCursor(6,1);
            lcd.print("LIMON");
            delay(1000);
            lcd.clear();
            if(count >= 8){
              lcd.setCursor(3,0);
              lcd.print("Aguarde un");
              lcd.setCursor(5,1);
              lcd.print("momento");
              digitalWrite (Motor2, HIGH);
              delay(1000);
              digitalWrite (Motor2, LOW);
              lcd.clear();
              lcd.setCursor(1,0);
              lcd.print("Bebida lista");
              delay(1000);
              lcd.clear();
               lcd.setCursor(0,0);
                lcd.print("cambio: ");
                count = count - 8;
                lcd.setCursor(2,1);
                lcd.print(count);
                delay(1000);
                lcd.clear();
                sig =0;
                count = 0;
                 lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("ingrese monedas");
                lcd.setCursor(0,1);
                lcd.print("> ");
                lcd.print(count);

                
              } else {
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("No alcanza");
                    delay(250);
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
                lcd.clear();
                lcd.setCursor(3,0);
                lcd.print("Preparando:");
                lcd.setCursor(7,1);
                lcd.print("UVA");
                delay(1000);
                lcd.clear();
                if(count >= 15){
                  lcd.setCursor(3,0);
                  lcd.print("Aguarde un");
                  lcd.setCursor(5,1);
                  lcd.print("momento");
                  digitalWrite (Motor3, HIGH);
                  delay(1000);
                  digitalWrite (Motor3, LOW);
                  lcd.clear();

                  lcd.setCursor(1,0);
                  lcd.print("Bebida lista");
                  delay(1000);
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("cambio: ");
                  count = count - 15;
                  lcd.setCursor(2,1);
                  lcd.print(count);
                  delay(1000);
                  lcd.clear();
                  sig =0;
                  count = 0;
                   lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("ingrese monedas");
                  lcd.setCursor(0,1);
                  lcd.print("> ");
                  lcd.print(count);

                } else {
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("No alcanza");
                    delay(250);
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("ingrese monedas");
                    lcd.setCursor(0,1);
                    lcd.print("> ");
                    lcd.print(count);
                    

                    } 
               }
             }
              /*  {
                if(digitalRead(producto4)==0){
                  lcd.clear();
                  lcd.setCursor(3,0);
                  lcd.print("Preparando:");
                  lcd.setCursor(5,1);
                  lcd.print("MANZANA");
                  delay(500);
                  lcd.clear();
                    if(count >= 20){
                      lcd.setCursor(3,0);
                      lcd.print("Aguarde un");
                      lcd.setCursor(5,1);
                      lcd.print("momento");
                      digitalWrite (Motor4, HIGH);
                      delay(100);
                      digitalWrite (Motor4, LOW);
                      lcd.clear();
                      lcd.setCursor(1,0);
                      lcd.print("Bebida lista");
                      delay(1000);
                      lcd.clear();
                      lcd.setCursor(0,0);
                      lcd.print("cambio: ");
                      count = count - 20;
                      lcd.setCursor(2,1);
                      lcd.print(count);
                      delay(1000);
                      lcd.clear();
                       
                      sig =0;
                      count = 0;
                      lcd.clear();  
                      lcd.setCursor(0,0);
                      lcd.print("ingrese monedas");
                      } else {
                          lcd.clear();
                          lcd.setCursor(0,0);
                          lcd.print("No alcanzo el");
                          lcd.setCursor(0,1);
                          lcd.print("Dinero");
                          delay(500);
                          
                          lcd.clear();  
                          lcd.setCursor(0,0);
                          lcd.print("ingrese monedas"); 
                      } 
                }
              }*/
  

  
  if (moneda1_state == 0 && prestate == 0) {
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
  
 
  

  
