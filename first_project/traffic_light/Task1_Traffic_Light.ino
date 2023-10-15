#define RED_LED     8
#define YELLOW_LED  9
#define GREEN_LED   10
#define BUTTON      11
#define PRESSURE    0
unsigned int carsNum = 0;
void setup() 
{
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(PRESSURE, INPUT);
}

void loop() 
{
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  int value = analogRead(PRESSURE);
  if ( value > 500)
  {
    carsNum++;
  }
  if (carsNum > 2)
  {
    for(int i = 0 ; i<=5 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(100);
    }
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(5 * carsNum);   //bug
    carsNum = 0;         
    for(int i = 0 ; i<=5 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(100);
    }
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  else if((digitalRead(BUTTON)) && (digitalRead(GREEN_LED)))   //bug 
  {
    for(int i = 0 ; i<=5 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(100);
    }
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  delay(500)S;
}
