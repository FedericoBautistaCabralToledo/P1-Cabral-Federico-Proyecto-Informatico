
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
  Serial.begin(9600);
  Puerta1.attach(A0);
  Puerta1.write(0);
  Puerta2.attach(A1);
  Puerta2.write(0);
  
  pinMode(ValorMovimiento1,INPUT);
  pinMode(ValorMovimiento2,INPUT);
  pinMode(Buzzer,INPUT);
  pinMode(Bombilla,OUTPUT);
  pinMode(A4,INPUT);	

  
  
}

void loop()
{
  ValorLuz = analogRead(SensorLuz);
  
 ValorMovimiento1 = digitalRead(Movimiento1);
 ValorMovimiento2 = digitalRead(Movimiento2);
  
 VerificarMovimiento();
 VerificarLuz();  
}

void AbrirPuertas(bool ValorMovimiento1)
{
  playMidi(Buzzer, midi1, ARRAY_LEN(midi1));
  Puerta1.write(220);
  Puerta2.write(220);
}

void CerrarPuertas()
{
  if (ValorPuerta1 > 0 && ValorPuerta2 > 0)
  {
   Puerta1.write(90);
   Puerta2.write(90);
  }
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
  if (ValorMovimiento1 == HIGH)
    {
    AbrirPuertas(ValorMovimiento1);
  	}
  if (ValorMovimiento2 == HIGH)
  {
    playMidi(Buzzer, midi2, ARRAY_LEN(midi1));
    CerrarPuertas();
  }
  if (ValorMovimiento1 == LOW && ValorMovimiento2 == LOW)
    {
    CerrarPuertas();
  	}
}
