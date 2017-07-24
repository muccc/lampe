// Einstellungen werden bei Aktivierung von der setup()-Methode automatisch vorgenommen:

void setup() {
  lichtaus_init();
  ui_init();
}

//Attribute für die Farben Rot Grün Blau (im Regenbogenmodus)
int regenbogen_r = 255;
int regenbogen_g = 0;
int regenbogen_b = 0;

//Attribute für die Farben Rot Grün Blau (im Regenbogenmodus)
int r = 0;
int g = 0;
int b = 0;

//Methode, die die Farbe im Regenbogen einen winzigen Schritt weiter schaltet
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

// Die Loop-Methode läuft automatisch nach der Setup-Methode in einer Endlosschleife.
void loop() {
  int lichtLevel = lichtein_getLevel();

  if(
      !ui_isPressed(1) && !ui_isPressed(2) && !ui_isPressed(3) && !ui_isPressed(14) 
      && r == 0 && g == 0 && b == 0 
      && lichtLevel > 300 
    ){
    ui_setLed(4, 1);
    regenbogen(); 
    delay(10);
    ui_setLed(4, 0);
  } else {
    
    if(ui_isPressed(1)) {
      while (ui_isPressed(1)) {delay(10);}
      if (r==0) {
        r = 255;
        ui_setLed(1, 1);
      } else {
        r = 0;
        ui_setLed(1, 0);
      }
    }
    if(ui_isPressed(2)) {
      while (ui_isPressed(2)) {delay(10);}
      if (g==0) {
        g = 255;
        ui_setLed(2, 1);
      } else {
        g = 0;
        ui_setLed(2, 0);
      }

    }
    if(ui_isPressed(3)) {
      while (ui_isPressed(3)) {delay(10);}
      if (b==0) {
        b = 255;
        ui_setLed(3, 1);
      } else {
        b = 0;
        ui_setLed(3, 0);
      }

    }
    if(ui_isPressed(4)) {
      while (ui_isPressed(4)) {delay(10);}
      r = g = b = 0;
      ui_setLed(1, 0);
      ui_setLed(2, 0);
      ui_setLed(3, 0);
    }
    lichtaus_setLeds(r, g, b);
  }
}
