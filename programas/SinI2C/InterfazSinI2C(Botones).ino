#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int SenRR=25;
float SenRat=2.5;


void setup() {
  lcd.begin(20,4);

  pinMode(10,INPUT);// bajar respiratory rate
  pinMode(11,INPUT);//subir respiratory rate
  pinMode(12,INPUT);// bajar IE ratio
  pinMode(13,INPUT);// subir IE ratio
  //Se coloca el cursor en la primera fila, y se deja este mensaje fijo
  //Linea 0
  lcd.setCursor(0,0); // ubica cursor en columna 0, linea 0
  lcd.print("Set:");
  lcd.setCursor(11,0);// ubica cursor en columna 11, linea 0
  lcd.print("P(cmH2O):");
  
  //Linea 1
  lcd.setCursor(1, 1);      // ubica cursor en columna 1, linea 1
  lcd.print("V=");       // escribo el volumen es igual
  lcd.setCursor(5, 1);      // ubica cursor en columna 5, linea 1
  lcd.print("% max");     //escribo % max
  lcd.setCursor(13,1);    // ubica cursor en columna 13, linea 1
  lcd.print("peak="); 
  
  //Linea 2
  lcd.setCursor(1, 2);      // ubica cursor en columna 1, linea 2
  lcd.print("RR=");
  lcd.setCursor( 6, 2);     // ubica cursor en columna 6, linea 2
  lcd.print("/min"); 
  lcd.setCursor(13,2);    // ubica cursor en columna 13, linea 2
  lcd.print("plat="); 
  
  //Linea 3
  lcd.setCursor(1, 3);      // ubica cursor en columna 1, linea 3
  lcd.print("I:E=1:");
  lcd.setCursor(13,3);    // ubica cursor en columna 13, linea 3
  lcd.print("PEEP="); 
}

void loop() {
  //Lectura del "Control"
  char dato= Serial.read();
  if (digitalRead(10)== HIGH) {
        SenRRdown();
        }   
    if (digitalRead(11)== HIGH) {
        SenRRup();
        } 
    if (digitalRead(12)== HIGH) {
        SenRatdown();
        }   
    if (digitalRead(13)== HIGH) {
        SenRatup();
        }
    int SenVol=map(analogRead(0), 0, 1023, 0, 100);
  if (dato=='A'){
    
    //Display del potenciometro para el Volumen
  //Linea 1
  lcd.setCursor(3, 1);      // ubica cursor en columna 1, linea 1
    lcd.print(SenVol);


    // Cursor en la 2° posición de la 3° fila
    //Display del potenciometro para la taza respiratoria
  //Linea 2
    lcd.setCursor(4,2);
    lcd.print(SenRR); //Solo tine un decimal
   
   
   
    //Display del potenciometro para el la relacion I/E
  //Linea 3
    lcd.setCursor(7,3);
    lcd.print(SenRat);


    //Envia un caracter para finalizar la comunicacion
    Serial.println("D");
    //Delay para que descanse un poco
    delay(200);

  }

}

void SenRRup(){
  SenRR= SenRR+1;
}
 
void SenRRdown(){
  SenRR = SenRR-1;
}

void SenRatup(){
  SenRat= SenRat+0.1;
}
 
void SenRatdown(){
  SenRat = SenRat-0.1;
}