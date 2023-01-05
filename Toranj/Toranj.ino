
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

#include <Servo.h>
Servo myservo;
int val;


#include <Stepper.h>

#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)

Stepper stepper(STEPS, 8, 10, 9, 11);



void setup() 
{
lcd.init(); //Im Setup wird der LCD gestartet 
lcd.backlight(); //Hintergrundbeleuchtung einschalten (lcd.noBacklight(); schaltet die Beleuchtung aus). 
myservo.attach(7);
}

void loop() 
{ 
lcd.setCursor(0, 0);//Hier wird die Position des ersten Zeichens festgelegt. In diesem Fall bedeutet (0,0) das erste Zeichen in der ersten Zeile. 
lcd.print("Pouyan"); 
lcd.setCursor(0, 1);// In diesem Fall bedeutet (0,1) das erste Zeichen in der zweiten Zeile. 
lcd.print("Viel Erfolg!"); 
delay(1000);

  val = analogRead(5);
  // 10-bit Wert des Analogeingangs (0-1023) in Winkel 0-180 umrechnen
  val = map(val, 0, 1023, 0, 180);
 
  // Errechneten Winkel zur Kontrolle an den PC übertragen (Seriellen Monitor starten!)

  // Einstellwinkel in Grad an das Servo-Objekt schicken
  myservo.write(val);
  // Kurze Pause, damit der Servo die neue Position anfahren kann
  delay(1000);


  stepper.setSpeed(1); // 1 rpm
  stepper.step(2038); // do 2038 steps – corresponds to one revolution in one minute
  delay(1000); // wait for one second
  stepper.setSpeed(6); // 6 rpm
  stepper.step(-2038); // do 2038 steps in the other direction with faster speed – corresponds to one revolution in 10 seconds
 delay(1000);
    val = analogRead(5);
  // 10-bit Wert des Analogeingangs (0-1023) in Winkel 0-180 umrechnen
  val = map(val, 0, 1023, 0, 180);
 
  // Errechneten Winkel zur Kontrolle an den PC übertragen (Seriellen Monitor starten!)

  // Einstellwinkel in Grad an das Servo-Objekt schicken
  myservo.write(val);
  // Kurze Pause, damit der Servo die neue Position anfahren kann
  delay(1000);

} 
