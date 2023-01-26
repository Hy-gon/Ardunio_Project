int switchstate = NULL;

void setup() 
{
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() 
{
 switchstate = digitalRead(2);
 if (switchstate)
 {
    digitalWrite(3, HIGH);
    tone(6, 800, 400);
    delay(1000);
    digitalWrite(4, HIGH);
    tone(6, 800, 400);
    delay(1000);
    digitalWrite(5, HIGH);
    tone(6, 1100, 800);
    delay(2000);  
 }
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
}