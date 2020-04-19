#include <LiquidCrystal.h>

LiquidCrystal lcd (7,6,5,4,3,2);

//Pines para poteciometros a usar

int potpin1 = A0;// pin para potenciometro de volumen de inspirado (debe ir de o% a 100%)
int potpin2= A1;//pin para potenciometro de varia el BPM(Rango de 10-40)
int potpin3= A2;//pin para potenciometro Varía la relación I: E. (Rango de 1:1 a 1:4(debe tener un decimal)) 
int potpin4= A3;//pin para potenciometro establece el umbral de presión para detectar el control de asistencia. Esto varía según lo descrito en el documento clínico.


// inicializamos las variables 
int valorvolu = 0;
int valorBPM = 0;
int valorIE = 0;

void setup() {
  lcd.begin(20, 4);      // inicializa a display de 20 columnas y 4 lineas
  Serial.begin (9600);// inicializo la comunicacion serial en 9600 baudios
}

void loop() {
  //Linea 0
  lcd.setCursor(0, 0);      // ubica cursor en columna 0, linea 0
  lcd.print("Set:");  // escribo el set and alamr display

  lcd.setCursor(11,0);// ubica cursor en columna 11, linea 0
  lcd.print("P(cmH20):"); //escribo lo que mido de Presion (cmH20)


  //Linea 1
  lcd.setCursor(1, 1);      // ubica cursor en columna 1, linea 1
  lcd.print("V="); // escribo el volumen es igual

  valorvolu=analogRead(potpin1);
  valorvolu = map(valorvolu,0,1023,0,100);
  lcd.print(valorvolu);
  
  lcd.setCursor(5, 1);      // ubica cursor en columna 5, linea 1
  lcd.print("% max"); //escribo % max

  lcd.setCursor(13,1);// ubica cursor en columna 13, linea 1
  lcd.print("peak="); 


  //Linea 2
  lcd.setCursor(1, 2);      // ubica cursor en columna 1, linea 2
  lcd.print("RR=");

  valorBPM=analogRead(potpin2);
  valorBPM = map(valorBPM,0,1023,10,40);
  lcd.print(valorBPM);

  lcd.setCursor( 6, 2);      // ubica cursor en columna 6, linea 2
  lcd.print("/min"); 

  lcd.setCursor(13,2);// ubica cursor en columna 13, linea 2
  lcd.print("plat="); 

  
  //Linea 3
  lcd.setCursor(1, 3);      // ubica cursor en columna 1, linea 3
  lcd.print("I:E=1:");

  valorIE=analogRead(potpin3);
  valorIE = map(valorIE,0,1023,10,40);// map no devuelve decimales
  valorIE= valorIE / 10;//Truco para llevarlo a decimales
  lcd.print(valorIE);

  lcd.setCursor(13,3);// ubica cursor en columna 13, linea 3
  lcd.print("PEEP="); 

  
 
}
