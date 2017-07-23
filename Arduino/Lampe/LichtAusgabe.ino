#define RED1  3
#define RED2  9

#define GREEN1  5
#define GREEN2  10

#define BLUE1  6
#define BLUE2  11

void lichtaus_init(void)
{
  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(BLUE1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(BLUE2, OUTPUT);
}

void lichtaus_setLed(int led, int r, int g, int b)
{
  if(led == 1) {
    analogWrite(RED1, r);
    analogWrite(GREEN1, g);
    analogWrite(BLUE1, b);
  }
  if(led == 2) {
    analogWrite(RED2, r);
    analogWrite(GREEN2, g);
    analogWrite(BLUE2, b);
  }
}

void lichtaus_setLeds(int r, int g, int b)
{
  lichtaus_setLed(1, r, g, b);
  lichtaus_setLed(2, r, g, b);
}

int lichtein_getLevel(void)
{
  int sensorValue = analogRead(A0);
  return sensorValue;
}

