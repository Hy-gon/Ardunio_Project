/* Initialisation Couleurs */
const byte COLOR_BLACK = 0b000;
const byte COLOR_RED = 0b100;
const byte COLOR_GREEN = 0b010;
const byte COLOR_BLUE = 0b001;
const byte COLOR_MAGENTA = 0b101;
const byte COLOR_CYAN = 0b011;
const byte COLOR_YELLOW = 0b110;
const byte COLOR_WHITE = 0b111;

/* Initialisation Pin LED */
const int PIN_LED_R = 4;
const int PIN_LED_G = 6;
const int PIN_LED_B = 5;

byte tab[] = {COLOR_BLACK,
              COLOR_RED,
              COLOR_GREEN,
              COLOR_BLUE,
              COLOR_MAGENTA,
              COLOR_CYAN,
              COLOR_YELLOW,
              COLOR_WHITE};

void setup() 
{
  /* Initialisation globale*/
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(3, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  buttonWaitColor(3, 7);
}

void displayColor(byte color) 
{
  /* Lecture couleur sur Pin */
  digitalWrite(PIN_LED_R, bitRead(color, 2));
  digitalWrite(PIN_LED_G, bitRead(color, 1));
  digitalWrite(PIN_LED_B, bitRead(color, 0));
}

int check_cmp(int cmp)
{
  /* Check CMP */
  if (cmp > 7)
    cmp = 7;
  else if (cmp < 0)
    cmp = 0;
  return (cmp);
}

void  buttonWaitColor(int buttonPin, int buttonPin2)
{
  /* Choix couleur � chaque appuis sur le bouton */
  int cmp = 0;
  int start = 1;
  
  while (1)
  {
    int buttonState = 0;
    int buttonState2 = 0;
    
    buttonState = digitalRead(buttonPin);
    buttonState2 = digitalRead(buttonPin2);
    if ((buttonState == HIGH || buttonState2 == HIGH || start == 1) && ((buttonState && buttonState2) != HIGH))
    {
        start = 0;
      if (buttonState == HIGH)
      {
        cmp--;
        delay(200);
      }
      else if (buttonState2 == HIGH)
      {
        cmp++;
        delay(200);
      }
      cmp = check_cmp(cmp);
      displayColor(tab[cmp]);
    }
    Serial.println(cmp);
  }
}
