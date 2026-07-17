#define AMARILLO 7
#define VERDE 4
#define ROJO 2
int valorluz;
int valorpote;
int valortemp;
bool valormovimiento;

void setup()
{
pinMode(AMARILLO, INPUT);
pinMode(VERDE, INPUT);
pinMode(ROJO, INPUT);
  
valorluz = analogRead(A4);
valortemp = analogRead(A5); 
valorpote = analogRead(A3);
valormovimiento = digitalRead(8);
valorluz = map(valorluz,0,1017,0,100);
valortemp = map(valortemp,0,153,0,100);
Serial.begin(9800);
}

void loop()
{
 if (valorpote > 50 && valorpote < 75 && valortemp < 15)
 {
  if (valormovimiento = HIGH)
  {
   digitalWrite(ROJO, HIGH);
   delay (1000);
   digitalWrite(ROJO, LOW);
    delay(1000);
    
   digitalWrite(VERDE, HIGH);
   delay (1000);
   digitalWrite(VERDE, LOW);
   delay(1000);
    
   digitalWrite(AMARILLO, HIGH);
   delay (1000);
   digitalWrite(AMARILLO, LOW);
   delay(1000);
  }
   if (valorluz = 100)
   {
    digitalWrite(ROJO, HIGH);
    digitalWrite(VERDE, HIGH);
    digitalWrite(AMARILLO, HIGH);
    delay (1000);
    digitalWrite(ROJO, LOW);
    digitalWrite(VERDE, LOW);
    digitalWrite(AMARILLO, LOW);
   }
 }
}