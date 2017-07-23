#define LED1  A3
#define LED2  A2
#define LED3  A5
#define LED4  A4

#define BUTTON1 2
#define BUTTON2 4
#define BUTTON3 8
#define BUTTON4 7

int ui_init(void)
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
}

void ui_setLed(int led, int an)
{
  if(led == 1) {
    if(an) {
      digitalWrite(LED1, HIGH);
    } else {
      digitalWrite(LED1, LOW);
    }
  }
  if(led == 2) {
    if(an) {
      digitalWrite(LED2, HIGH);
    } else {
      digitalWrite(LED2, LOW);
    }
  }
  if(led == 3) {
    if(an) {
      digitalWrite(LED3, HIGH);
    } else {
      digitalWrite(LED3, LOW);
    }
  }
  if(led == 4) {
    if(an) {
      digitalWrite(LED4, HIGH);
    } else {
      digitalWrite(LED4, LOW);
    }
  }
}

int ui_isPressed(int button)
{
  if(button == 1) {
    if(digitalRead(BUTTON1) == LOW) {
      return 1;
    }
  }
  if(button == 2) {
    if(digitalRead(BUTTON2) == LOW) {
      return 1;
    }
  }
  if(button == 3) {
    if(digitalRead(BUTTON3) == LOW) {
      return 1;
    }
  }
  if(button == 4) {
    if(digitalRead(BUTTON4) == LOW) {
      return 1;
    }
  }
  return 0;
}

