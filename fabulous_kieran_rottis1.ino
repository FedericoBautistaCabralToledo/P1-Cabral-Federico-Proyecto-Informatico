#include <Servo.h>

#define MOV 8
#define BOTON 4

bool valorBoton;
bool valorMovi;
int rotacion = 90;
int celsius;
int valorTemp;

Servo servo1;
Servo servo2;

void setup()
{
  pinMode(BOTON, INPUT);
  pinMode(MOV, INPUT); 
  pinMode(A2, INPUT);
  
  servo1.attach(A0);
  servo1.write(90);
  servo2.attach(A1);
  servo2.write(90);
}

void loop()
{
  Servo90a180();
  HayMovimiento();
  TemperaturaMayorA35();
  SinMovimiento();
}

void Servo90a180()
{
  valorBoton = digitalRead(BOTON);
  
  if (valorBoton == LOW)
  {
    rotacion = rotacion + 90;
    if (rotacion > 180) 
    rotacion = 180;
    servo1.write(rotacion);
    servo2.write(rotacion);
    delay(3000);
  }
  
  if (rotacion > 180)
  {
    rotacion = rotacion - 90;
    servo1.write(rotacion);
    servo2.write(rotacion);
    delay(3000);
  }
}

void HayMovimiento()
{
  if (valorBoton == LOW)
  {
    valorMovi = digitalRead(MOV);
  }
  
  if (valorMovi == LOW)
  {
    rotacion = 0;
    servo1.write(rotacion);
    servo2.write(rotacion);
    delay(6000);
  }
}

void TemperaturaMayorA35()
{
  valorTemp = analogRead(A2);
  celsius = map(((valorTemp - 20) * 3.04), 0, 1023, -40, 125);
 
  if (celsius > 35)
  {
    servo1.write(rotacion);
    servo2.write(rotacion);
  }
}

void SinMovimiento()
{
  if (valorBoton == HIGH)
  {
    if (rotacion > 45)
    {
      rotacion = rotacion + 5;
      if (rotacion > 180) rotacion = 180;
      servo1.write(rotacion);
      servo2.write(rotacion);
    }
    else if (rotacion < 45)
    {
      rotacion = rotacion - 5;
      if (rotacion < 0) rotacion = 0;
      servo1.write(rotacion);
      servo2.write(rotacion);
    }
    
    if (rotacion == 45)
    {
      servo1.write(rotacion);
      servo2.write(rotacion);
    }
    delay(100);
  } 
}