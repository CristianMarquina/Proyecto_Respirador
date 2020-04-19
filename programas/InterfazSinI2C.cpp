#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(20,4);
  //Se coloca el cursor en la primera fila, y se deja este mensaje fijo
  lcd.setCursor(0,0);
  lcd.print("Set:");
  lcd.setCursor(11,0);
  lcd.print("(PcmH2O):");
}

void loop() {
  //Lectura del "Control"
  char dato= Serial.read();
  if (dato=='A'){
    int SenVol=map(analogRead(0), 0, 1023, 0, 100);
    int SenRR=map(analogRead(1), 0, 1023, 10, 40);
    float SenRat= 1.0+ map(analogRead(2), 0, 1023, 0, 30)/10;
    // Cursor en la 2° posición de la 2° fila
    //Display del potenciometro para el Volumen
    lcd.setCursor(1,1);
    lcd.print("V=");
    lcd.print(SenVol);
    lcd.print("% max");

    //Display del valor pico de la presion de inspiracion
    lcd.setCursor(13,1);
    lcd.print("peak=10");

    // Cursor en la 2° posición de la 3° fila
    //Display del potenciometro para la taza respiratoria
    lcd.setCursor(1,2);
    lcd.print("RR=");
    lcd.print(SenRR); //Solo tine un decimal
    lcd.print("/min");

    //Display para el plateau preassure
    lcd.setCursor(13,2);
    lcd.print("plat= 0");

    // Cursor en la 2° posición de la 4° fila
    //Display del potenciometro para el la relacion I/E
    lcd.setCursor(1,3);
    lcd.print("I:E=1:");
    lcd.print(SenRat);

    //Display para el PEEP
    lcd.setCursor(13,3);
    lcd.print("PEEP= 0");

    //Envia un caracter para finalizar la comunicacion
    Serial.println("D");
    
    //Delay para que descanse un poco
    delay(200);

  }

}