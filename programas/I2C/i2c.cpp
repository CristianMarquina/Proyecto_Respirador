#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

void setup() {
	// Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();

  //Se coloca el cursor en la primera fila, y se deja este mensaje fijo
  lcd.setCursor(0,0);
  lcd.print("Set:");
  lcd.setCursor(11,0);
  lcd.print("(PcmH2O):");
  lcd.setCursor(1,1);
  // Cursor en la 2° posición de la 2° fila para colocar el Volumen
  lcd.print("V=");
  lcd.setCursor(6,1);
  lcd.print("% max");
  //Display del valor pico de la presion de inspiracion
  lcd.setCursor(13,1);
  lcd.print("peak=10");
  lcd.setCursor(1,2);
  // Cursor en la 2° posición de la 3° fila para colocar RR
  lcd.print("RR=");
  lcd.setCursor(6,2);
  lcd.print("/min");
  //Display para el plateau preassure
  lcd.setCursor(13,2);
  lcd.print("plat= 0");
  // Cursor en la 2° posición de la 4° fila para colocar I/E
  lcd.setCursor(1,3);
  lcd.print("I:E=1:");
  //Display para el PEEP
  lcd.setCursor(13,3);
  lcd.print("PEEP= 0");
  
}

void loop() {
  int SenVol=map(analogRead(0), 0, 1023, 0, 100);
  int SenRR=map(analogRead(1), 0, 1023, 10, 40);
  float SenRat=map(analogRead(2), 0, 1023, 10, 40)/10;

  //Lectura del "Control"
  char dato= Serial.read();
  if (dato=='A'){

    //Display del potenciometro para el valor del Volumen
    // Cursor en la 3° posición de la 2° fila
    lcd.setCursor(3,1);
    lcd.print(SenVol);


    //Display del potenciometro para el valor de la taza respiratoria
    // Cursor en la 4° posición de la 3° fila
    lcd.setCursor(4,2);
    lcd.print(SenRR); //Solo tine un decimal

    
    //Display del potenciometro para el valor de la relacion I/E
    // Cursor en la 7° posición de la 4° fila
    lcd.setCursor(7,3);
    lcd.print(SenRat);

    

    //Envia un caracter para finalizar la comunicacion
    Serial.println("D");
    
    //Delay para que descanse un poco
    delay(200);

  }

} 