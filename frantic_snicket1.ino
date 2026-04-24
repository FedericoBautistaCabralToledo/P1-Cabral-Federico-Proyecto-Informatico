// C++ code
//
#define R 11
#define A 10
#define V 6
#define PR A0
#define PA A1
#define PV A2
#define Boton 2
int ValorRojo;
int ValorVerde;
int ValorAzul;
bool ValorBoton;

void setup()
{
  pinMode(Boton, INPUT);
  pinMode(R, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9800);
}

void loop()
{
    ValorBoton = digitalRead(Boton);  
   delay (100);
  if (ValorBoton == LOW){
    Serial.println("TENES 10 SEGUNDOS PARA CONFIGURAR EL LED");
      delay (10000);
  ValorRojo = analogRead(PR);
  ValorVerde = analogRead(PV);
  ValorAzul= analogRead(PA);
  ValorRojo = map(ValorRojo, 0, 1023, 0, 255);
  ValorAzul = map(ValorAzul, 0, 1023, 0, 255);
  ValorVerde = map(ValorVerde, 0, 1023, 0, 255);
  delay(100);
    Serial.print("EL LED ESTA USANDO ESTA CONFIGURACION: ");
    Serial.println(ValorRojo);
    Serial.println(ValorVerde);
    Serial.println(ValorAzul);

PrendeYApaga();
  }
}
void PrendeYApaga()
{
analogWrite(R, ValorRojo);
  analogWrite(V, ValorVerde);
  analogWrite(A, ValorAzul);
  delay(10000);
   analogWrite(R, 0);
  analogWrite(V, 0);
  analogWrite(A, 0);
}