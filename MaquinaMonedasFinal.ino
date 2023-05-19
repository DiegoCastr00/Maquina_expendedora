#include <Wire.h>
#include  <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x3F, 16, 2);

const int btnReset = 28;

// Puertos de entrada y salida del sensor
const int sensorEntrada = 18;   // Cambia el número de pin según corresponda
const int sensorSalida = 19;    // Cambia el número de pin según corresponda

// Puertos para diferenciar el tamaño de las monedas
const int sMoneda1 = 30;        // Cambia el número de pin según corresponda
const int sMoneda2 = 32;        // Cambia el número de pin según corresponda
const int sMoneda3 = 34;        // Cambia el número de pin según corresponda
const int sMoneda4 = 36;        // Cambia el número de pin según corresponda

// Variables para la cantidad de monedas por separado
int monCincuenta = 0;
int monUno = 0;
int monDos = 0;
int monCinco = 0;
int monDiez = 0;

// Variable para la suma total de monedas
double dineroTotal = 0;
int monedasTotales = 0;

// Variables que se utilizan dentro de la interrupcion
volatile boolean senEntrada = LOW;
volatile boolean senSalida = HIGH;
volatile boolean monedaNueva = LOW;

// Guarda la lectura de los tamaños de monedas
boolean boolMoneda1 = LOW;
boolean boolMoneda2 = LOW;
boolean boolMoneda3 = LOW;
boolean boolMoneda4 = LOW;

// Función que se ejecuta cuando se inserta una moneda en el sensor
void Ext_INT_sensorEntrada() {
  senEntrada = HIGH;
  senSalida = LOW;
}

// Función que se ejecuta cuando sale la moneda del sensor
void Ext_INT_sensorSalida() {
  senEntrada = LOW;
  senSalida = HIGH;
}

// Configuración inicial
void setup() {
  
  Wire.begin();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.backlight();

  Serial.begin(9600);

  pinMode(sensorEntrada, INPUT_PULLUP);
  pinMode(sensorSalida, INPUT_PULLUP);
  pinMode(sMoneda1, INPUT_PULLUP);
  pinMode(sMoneda2, INPUT_PULLUP);
  pinMode(sMoneda3, INPUT_PULLUP);
  pinMode(sMoneda4, INPUT_PULLUP);
  pinMode(btnReset, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(sensorEntrada), Ext_INT_sensorEntrada, RISING);
  attachInterrupt(digitalPinToInterrupt(sensorSalida), Ext_INT_sensorSalida, FALLING);
}

// Bucle repetitivo
void loop() {

  // Verifica la entrada de una moneda
  if (senEntrada == HIGH && senSalida == LOW) {
    monedaNueva = HIGH;
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("Sensando Moneda...");
    Serial.println("Sensando Moneda...");
    leerValorMonedas();
  }

  // Verifica que haya salido la moneda
  if (senEntrada == LOW && senSalida == HIGH) {

    // Pregunta si tenemos una moneda nueva y determina su valor
    if (monedaNueva == HIGH) {
      asignarValorMoneda();
      monedaNueva = LOW;

      // Cálculo de total de monedas y dinero
      monedasTotales = monCincuenta + monUno + monDos + monCinco + monDiez;
      dineroTotal = (monCincuenta * 0.5) + (monUno * 1) + (monDos * 2) + (monCinco * 5) + (monDiez * 10);

      Serial.print("$0.5:");
      Serial.print(monCincuenta);
      Serial.print(" $1:");
      Serial.print(monUno);
      Serial.print(" $2:");
      Serial.print(monDos);
      Serial.print(" $5:");
      Serial.print(monCinco);
      Serial.print(" $10:");
      Serial.print(monDiez);
      Serial.print(" Total: $");
      Serial.print(dineroTotal);
      Serial.print(" Monedas:");
      Serial.print(monedasTotales);
      Serial.println();
    }
  }

  // Revisa si se ha presionado el botón de RESET
  if (digitalRead(btnReset) == LOW) {

    monCincuenta = 0;
    monUno = 0;
    monDos = 0;
    monCinco = 0;
    monDiez = 0;

    // Cálculo de total de monedas y dinero
    monedasTotales = 0;
    dineroTotal = 0;

    Serial.print("boton reset");
  }
}

// Función encargada de almacenar los sensores que fueron activados
void leerValorMonedas() {
  if (digitalRead(sMoneda1) == HIGH) {
    boolMoneda1 = HIGH;
  }
  if (digitalRead(sMoneda2) == HIGH) {
    boolMoneda2 = HIGH;
  }
  if (digitalRead(sMoneda3) == HIGH) {
    boolMoneda3 = HIGH;
  }
  if (digitalRead(sMoneda4) == HIGH) {
    boolMoneda4 = HIGH;
  }
}

// Asigna el valor de la moneda y lo almacena
void asignarValorMoneda() {
  if (boolMoneda1 == HIGH) {
    if (boolMoneda2 == HIGH) {
      if (boolMoneda3 == HIGH) {
        if (boolMoneda4 == HIGH) {
          monDiez = monDiez + 1;
        }
        else {
          monCinco = monCinco + 1;
        }
      }
      else {
        monDos = monDos + 1;
      }
    }
    else {
      monUno = monUno + 1;
    }
  }
  else {
    monCincuenta = monCincuenta + 1;
  }
  // Resetea los valores de los sensores para leer otra moneda
  boolMoneda1 = LOW;
  boolMoneda2 = LOW;
  boolMoneda3 = LOW;
  boolMoneda4 = LOW;
}
