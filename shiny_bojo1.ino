#define R 4
#define A 7
#define P 12
#define L 8
void setup()
{
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, INPUT);
  pinMode(8, INPUT);
}

void loop()
{ 
  int luz;
  bool prende;
  bool presionado;
  bool movimiento;
  luz = analogRead(8);
  presionado = digitalRead(12);
  
  if (presionado == LOW)
  {
    if (luz > 266)
    {
      if (movimiento == HIGH)
   {
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
      }
      else if (movimiento == LOW)
      {
       digitalWrite(4, LOW);
       digitalWrite(7, LOW);
      }
     }
    }
  }
