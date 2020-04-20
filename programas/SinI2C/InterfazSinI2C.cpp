#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(20,4);
  
  //Se coloca el cursor en la primera fila, y se deja este mensaje fijo
  //Linea 0
  lcd.setCursor(0,0); // ubica cursor en columna 0, linea 0
  lcd.print("Set:");
<<<<<<< HEAD
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
=======
  lcd.setCursor(11,0);// ubica cursor en columna 11, linea 0
  lcd.print("P(cmH2O):");
  
  //Linea 1
  lcd.setCursor(1, 1);      // ubica cursor en columna 1, linea 1
  lcd.print("V="); 			// escribo el volumen es igual
  lcd.setCursor(5, 1);      // ubica cursor en columna 5, linea 1
  lcd.print("% max"); 		//escribo % max
  lcd.setCursor(13,1);		// ubica cursor en columna 13, linea 1
  lcd.print("peak="); 
  
  //Linea 2
  lcd.setCursor(1, 2);      // ubica cursor en columna 1, linea 2
  lcd.print("RR=");
  lcd.setCursor( 6, 2);     // ubica cursor en columna 6, linea 2
  lcd.print("/min"); 
  lcd.setCursor(13,2);		// ubica cursor en columna 13, linea 2
  lcd.print("plat="); 
  
  //Linea 3
  lcd.setCursor(1, 3);      // ubica cursor en columna 1, linea 3
  lcd.print("I:E=1:");
  lcd.setCursor(13,3);		// ubica cursor en columna 13, linea 3
  lcd.print("PEEP="); 
>>>>>>> 326c6b771fbf69feae808ebe69991854cfc53d32
}

void loop() {

  int SenVol=map(analogRead(0), 0, 1023, 0, 100);
  int SenRR=map(analogRead(1), 0, 1023, 10, 40);
  float SenRat= map(analogRead(2), 0, 1023, 10, 40)/10;

  //Lectura del "Control"
  char dato= Serial.read();
  if (dato=='A'){
<<<<<<< HEAD

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

    
=======
    int SenVol=map(analogRead(0), 0, 1023, 0, 100);
    int SenRR=map(analogRead(1), 0, 1023, 10, 40);
    float SenRat=  map(analogRead(2), 0, 1023, 10, 40)/10;
    
	
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

>>>>>>> 326c6b771fbf69feae808ebe69991854cfc53d32

    //Envia un caracter para finalizar la comunicacion
    Serial.println("D");
    //Delay para que descanse un poco
    delay(200);

  }

}