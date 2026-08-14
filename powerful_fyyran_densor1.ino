#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define B6 1976
#define Ab6 1865
#define A6 1760
#define Fb4 370
#define Gb4 415
#define A4 440
#define Ab4 466
#define B4 494
#define C5 523
#define Cb5 554
#define D5 587
  
#define Boton1 2
#define Boton2 4
#define Boton3 8

bool ValorB1;
bool ValorB2;
bool ValorB3;
  
const int midi1[52][3] = {
 {B6, 136, 0},
 {Ab6, 136, 0},
 {A6, 136, 0},
 {Fb4, 136, 0},
 {Gb4, 136, 0},
 {A4, 136, 0},
 {Ab4, 136, 0},
 {B4, 136, 0},
 {C5, 136, 0},
 {Cb5, 136, 0},
 {D5, 136, 0},
 {D5, 136, 0},
 {D5, 136, 0},
 {D5, 136, 0},
 {D5, 136, 0},
 {D5, 136, 0},
 {D5, 136, 0},
 {Cb5, 136, 0},
 {C5, 136, 0},
 {B4, 136, 0},
 {Ab4, 136, 0},
 {A4, 136, 0},
 {Gb4, 136, 0},
 {Fb4, 136, 0},
 {A6, 136, 0},
 {Ab6, 136, 0},
 {B6, 136, 0},
};

#define Fb4U 370
#define Gb4U 415
#define A4U 440
#define Ab4 466
#define B4U 494
#define C5U 523
#define Cb5U 554
#define D5U 587

const int midi2[25][3] = {
 {Fb4U, 136, 0},
 {Gb4U, 136, 0},
 {A4U, 136, 0},
 {Ab4, 136, 0},
 {B4U, 136, 0},
 {C5U, 136, 0},
 {Cb5U, 136, 0},
 {D5U, 136, 0},
 {D5U, 136, 0},
 {D5U, 136, 0},
 {D5U, 136, 0},
 {D5U, 136, 0},
 {D5U, 136, 0},
 {D5U, 136, 0},
 {Cb5U, 136, 0},
 {C5U, 136, 0},
 {B4U, 136, 0},
 {Ab4, 136, 0},
 {A4U, 136, 0},
 {Gb4U, 136, 0},
 {Fb4U, 136, 0},
};

#define B5 988
#define Cb5t 554
#define Fb5 740

const int midi3[69][3] = {
 {B5, 136, 0},
 {B5, 136, 0},
 {Cb5t, 136, 0},
 {B5, 136, 0},
 {B5, 136, 136},
 {Cb5t, 136, 0},
 {Fb5, 136, 0},
 {Fb5, 136, 0},
 {B5, 136, 136},
 {B5, 136, 0},
 {B5, 136, 0},
 {B5, 136, 0},
 {B5, 136, 136},
 {B5, 136, 0},
 {B5, 136, 0},
 {Cb5t, 136, 0},
 {B5, 136, 0},
 {B5, 136, 0},
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
  pinMode(Boton1, INPUT);
  pinMode(Boton2, INPUT);
  pinMode(Boton3, INPUT);
    Serial.begin(9800);
}

void loop()
{  
    Serial.println(ValorB2);
  
    ValorB1 = digitalRead(Boton1); 
    ValorB2 = digitalRead(Boton2); 
    ValorB3 = digitalRead(Boton3);
  
  if (ValorB1 == LOW)
  {
  playMidi(12, midi1, ARRAY_LEN(midi1));
  delay(2000);
  }
  
    if (ValorB2 == LOW)
  {
   playMidi(12, midi2, ARRAY_LEN(midi2)); 
   delay(2000);
  }
  
    if (ValorB3 == LOW)
  {
   playMidi(12, midi3, ARRAY_LEN(midi3));
   delay(2000);
  }
}