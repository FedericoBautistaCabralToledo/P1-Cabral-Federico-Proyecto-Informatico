// C++ code
//
void setup()
{
  pinMode(2 ,OUTPUT);
  pinMode(4 ,OUTPUT);
  pinMode(7 ,OUTPUT);
  pinMode(8 , INPUT);
  pinMode(12, OUTPUT);
  bool PRR;
}

void loop()
{
  
  PRR = digitalRead(8);
 //Sin movimiento
  if (PRR == LOW)
  {
    delay(1000);
   digitalWrite(2, HIGH);
    delay (1000);
    digitalWrite(2, LOW);
  }
  else if (PRR == HIGH)
  {
    //Con movimiento
    delay(1000);
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(7, LOW);
  }
}