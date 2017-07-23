// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lichtaus_init();
  ui_init();
}

int regenbogen_r = 255;
int regenbogen_g = 0;
int regenbogen_b = 0;

void regenbogen(void)
{
  if(regenbogen_b == 0 && regenbogen_r > 0) {
    regenbogen_r--;
    regenbogen_g++;
  }else if(regenbogen_r == 0 && regenbogen_g > 0) {
    regenbogen_g--;
    regenbogen_b++;
  }else if(regenbogen_g == 0 && regenbogen_b > 0) {
    regenbogen_b--;
    regenbogen_r++;
  }
  lichtaus_setLeds(regenbogen_r, regenbogen_g, regenbogen_b);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int lichtLevel = lichtein_getLevel();
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = lichtLevel * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);

  //int outputValue = lichtLevel / 4;
  //lichtaus_setLeds(outputValue, outputValue, outputValue);

  if((!(ui_isPressed(1) || ui_isPressed(2) || ui_isPressed(3) || ui_isPressed(4))) && lichtLevel > 1000){
    regenbogen();
    ui_setLed(1, 0);
    ui_setLed(2, 0);
    ui_setLed(3, 0);
    ui_setLed(4, 0);
    delay(10);
  } else {
    int r = 0;
    int g = 0;
    int b = 0;
    if(ui_isPressed(1)) {
      r = 255;
      ui_setLed(1, 0);
    }
    if(ui_isPressed(2)) {
      g = 255;
      ui_setLed(2, 0);

    }
    if(ui_isPressed(3)) {
      b = 255;
      ui_setLed(3, 0);

    }
    if(ui_isPressed(4)) {
      r = g = b = 255;
      ui_setLed(4, 0);

    }
    lichtaus_setLeds(r, g, b);
  }
}
