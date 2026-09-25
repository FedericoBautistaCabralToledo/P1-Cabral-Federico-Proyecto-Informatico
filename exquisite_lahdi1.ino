
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

const int midi1[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
#define Buzzer 2
#define Movimiento 3
#define ROJO 4 
#define AZUL 5
#define VERDE 6
#define Pote A1
#define TemperaturaA2

string ColorLED;
Servo servo1;
int ValorTemperatura;
int ValorTemperaturaREAL;
int ValorServo;
int ValorPote;
int CantidadVueltas;
bool ValorMovimiento;
bool ValorBuzzer;
bool ValorServoMOVI;

Adafruit_LiquidCrystal lcd1(32);

void setup()
{
  lcd1.begin();
  pinMode(Buzzer, OUTPUT);
  pinMode(Movimiento, OUTPUT);
  pinMode(Temperatura, OUTPUT);
  pinMode(Pote, INPUT);
}

void loop()
{
 PrenderLEDS();
 DetectarTemperatura(); 
 TextoLCD();
}

void PrenderLEDS()
{
  ValorTemperatura = analogRead(Temperatura);
  ValorTemperaturaREAL = map(ValorTemperatura, 0,358,-40,125);
  
  if (ValorTemperaturaREAL > 40)
  {
   digitalWrite(VERDE, LOW);
   digitalWrite(AZUL, LOW);
   digitalWrite(ROJO, HIGH); 
   ColorLED = "ROJO";
   delay(450);
  }
  else if (ValorTemperaturaREAL < 40)
  {
   digitalWrite(VERDE, LOW);
   digitalWrite(ROJO, LOW);
   digitalWrite(AZUL, HIGH); 
   ColorLED = "AZUL";
   delay(450);
  }
  else if (ValorBuzzer = LOW)
  {
   digitalWrite(VERDE, HIGH);
   digitalWrite(ROJO, LOW);
   digitalWrite(AZUL, LOW);
   ColorLED = "VERDE";
   delay(450);
  }
}

void TextoLCD()
{
  lcd1.setCursor(0,1);
  lcd1.setBacklight(1);
  
 if (ValorBuzzer = LOW)
 {
  lcd1.print("Melodia"); 
 }
  else if (ValorServoMOVI = LOW)
  {
   lcd1.print("Servo moviendose")
  }
  else if (ValorServoMOVI = HIGH && ValorBuzzer = HIGH)
  {
   lcd1.print(ColorLED); 
  }
}