
#define R 4
#define A 2
#define V 1
int valorluz;
int valortemp;
int celsius;
int valorluz2;

void setup()
{
  Serial.begin(9800);
  pinMode(R,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(V,OUTPUT);
}

void loop()
{
  valorluz2 = analogRead(A1);
  valortemp = analogRead (A2);
  Serial.println("El nivel de luz actual es ");
  valorluz2 = map(valorluz2,0,1017,0,100);
  Serial.println(valorluz2);
  
  Serial.println("y la temperatura actual: ");
  celsius = map(((valortemp - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(celsius);
  delay(1000);
  
  if (valorluz2 > 30 && valorluz2 < 70)
  {
  	if (celsius > 90) {
    analogWrite(R,255);
     delay(1000);
      analogWrite(R,0);
  	}
    
  	else if (celsius <= 18)
    {
   	analogWrite(A,255); 
      delay(1000);
      analogWrite(A,0);
  	}
    
  	else if (celsius > 18 && celsius <= 90)
    {
   	analogWrite(V,255);
       delay(1000);
      analogWrite(V,0);
  	}
  }
}


