#define V 3
#define A 5
#define R 6
void setup()
{
  pinMode(R, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(A, OUTPUT);
}
void loop()
{
for (int i = 1; i < 255; i++)
  {
    analogWrite(R, i);
    for (int i = 1; i < 255; i++)
  {
    analogWrite(V, i);
      
    for (int a = 1; a < 255; a++)
  {
    analogWrite(A, a);
    }
    }
}
}