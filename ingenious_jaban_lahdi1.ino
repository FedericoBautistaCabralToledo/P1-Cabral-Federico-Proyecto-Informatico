//Musica1
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Fb5 740
#define G5 784
#define Gb5 831
#define A5 880
#define Ab5 932

//Musica2
#define Ab3 233
#define Fb5G 740
#define C5 523
#define F6 1397
#define G4 392

//Componentes
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
#define Movimiento1 2
#define Movimiento2 3
#define Buzzer 13
#define SensorLuz A4
#define Bombilla 4
#define ValorPuerta1 A0
#define ValorPuerta2 A1


Servo Puerta1;
Servo Puerta2;
int ValorLuz;
int ValorLuzREAL;
bool ValorMovimiento1;
bool ValorMovimiento2;
bool PuertasAbiertas = LOW;
Adafruit_LiquidCrystal lcd1(32); 

const int midi1[5][3] =
{
 {Ab3, 136, 0},
 {Fb5, 136, 0},
 {C5, 136, 0},
 {F6, 136, 0},
 {G4, 136, 0},
};

const int midi2[5][3] = {
 {Fb5G, 273, 0},
 {G5, 273, 0},
 {Gb5, 273, 0},
 {A5, 273, 0},
 {Ab5, 273, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup()
{
  lcd1.begin(16, 2);
  lcd1.setBacklight(1);
  Puerta1.attach(A0);
  Puerta1.write(90);
  
  Puerta2.attach(A1);
  Puerta2.write(90);
  
  pinMode(Movimiento1,INPUT);
  pinMode(Movimiento2,INPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(Bombilla,OUTPUT);
  pinMode(SensorLuz,INPUT);	
}

void loop()
{
  ValorLuz = analogRead(SensorLuz);
  
 VerificarMovimiento();
 VerificarLuz();
  LCDMostrar();
}

void AbrirPuertas()
{
  Puerta1.write(180);
  Puerta2.write(180);
  delay(500);
}

void CerrarPuertas()
{
  Puerta1.write(90);
  Puerta2.write(90);
  delay(500);
}

void VerificarLuz()
{ 
  if (ValorLuz > 415)
  {
    digitalWrite(Bombilla,HIGH);
  }
  else
  {
    digitalWrite(Bombilla,LOW);
  }
  delay(760);
}

void VerificarMovimiento()
{
   ValorMovimiento1 = digitalRead(Movimiento1);
 ValorMovimiento2 = digitalRead(Movimiento2);
  
  if (ValorMovimiento1 == HIGH && PuertasAbiertas == LOW)
  {
   AbrirPuertas();
   PuertasAbiertas = HIGH;
   playMidi(Buzzer, midi1, ARRAY_LEN(midi1));
  }
  else if (ValorMovimiento1 == HIGH && PuertasAbiertas == HIGH)
  {
   CerrarPuertas();
   PuertasAbiertas = LOW;
   playMidi(Buzzer, midi2, ARRAY_LEN(midi1));
  }
  delay(2000);
  if (ValorMovimiento2 == HIGH && PuertasAbiertas == LOW)
  {
   AbrirPuertas();
   PuertasAbiertas = HIGH;
   playMidi(Buzzer, midi1, ARRAY_LEN(midi1));
  }
  else if (ValorMovimiento2 == HIGH && PuertasAbiertas == HIGH)
  {
   CerrarPuertas(); 
   PuertasAbiertas = LOW;
   playMidi(Buzzer, midi2, ARRAY_LEN(midi1));
  }
}

void LCDMostrar()
{
  lcd1.setCursor(0, 0);
 if (PuertasAbiertas == HIGH)
 {
   lcd1.print("Abierta");
 }
  else if (PuertasAbiertas == LOW)
  {
   lcd1.print("Cerrada"); 
  }
}
