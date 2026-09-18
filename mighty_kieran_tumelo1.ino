#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220
#define ROJO 2
#define VERDE 3
#define AZUL 4
#define Boton 5
#define Temperatura A1
#define Pote A2
#define Buzzer 6

int ValorSERVOMov;
bool ValorServo;
bool ValorBoton;
int ValorPote;
bool ValorBuzz;
int ValorTemperatura;
int ValorTemperaturaREAL;
int ValorEspera;
bool ValorMovServo;
Adafruit_LiquidCrystal lcd1(0);

const int midi1[10][3] = {
  {Gb3, 115, 0},
  {C4, 115, 0},
  {Gb3, 115, 0},
  {F3, 115, 0},
  {A3, 115, 115},
  {Gb3, 115, 0},
  {C4,115,0},
  {F3,115,0},
  {A3,115,0},
};

void playMidi(int pin, const int notes[][3], size_t len)
{
 for (int i = 0; i < len; i++)
 {
  tone(pin, notes[i][0]);
  delay(notes[i][1]);
  noTone(pin);
  delay(notes[i][2]);
 }
}

void setup()
{
  lcd1.begin();
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(Boton, INPUT);
  pinMode(Temperatura, OUTPUT);
  Servo.attach(A0);
  pinMode(Pote, INPUT);
}

void loop()
{
MoverServo();
PrenderLEDS();  
MostrarLCD();
}

void MoverServo()
{
  Servo.write(0);
  ValorSERVOMov = analogRead(A0);
 ValorBoton = digitalRead(Boton);
  ValorPote = analogRead(Pote);
  if (ValorPote < 25)
  {
   ValorEspera = 2000; 
  }
  else if (ValorPote > 25 && ValorPote < 50)
  {
   ValorEspera = 5000; 
  }
  else if (ValorPote > 50)
  {
   ValorEspera = 8000; 
  }
 if (ValorBoton == LOW)
 {
   for (int i = 0; i > 10; i++)
   {
   if (ValorSERVOMov > 89)
   {
    Servo.write(0); 
   }
     else if (ValorSERVOMov < 1)
     {
      Servo.write(90); 
     }
    delay(ValorEspera);
    ValorServo = HIGH;
   }
   playMidi(Buzzer, midi1, 9);
   ValorBuzz = HIGH;
}
}

void PrenderLEDS()
{
  ValorTemperatura = analogRead(A1);
  ValorTemperaturaREAL = map(ValorTemperatura, 0, 358, -40, 125);
  
  if (ValorTemperaturaREAL > 40)
  {
   digitalWrite(ROJO, HIGH);
  }
  else if (ValorTemperatura < 40)
  {
   digitalWrite(AZUL, HIGH); 
  }
  if (ValorBuzz = HIGH)
  {
    digitalWrite(VERDE, HIGH);
  }
}

void MostrarLCD()
{
  lcd1.setCursor(0,1);
  lcd1.setBacklight(1);
  if (ValorBuzz = HIGH)
  {
    lcd1.print("Melodia");
  }
  else if (ValorServo = HIGH)
  {
   lcd1.print("Servo moviendose"); 
  }
}