#define RED_LED     8
#define YELLOW_LED  9
#define GREEN_LED   10
#define BUTTON      2
#define BUZZER      12
#define PRESSURE    0

unsigned int carsNum = 0;

void setup() 
{
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, RISING);
  pinMode(PRESSURE, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() 
{
  digitalWrite(BUZZER, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  int value = analogRead(PRESSURE);
  if (value > 200)
  {
    carsNum++;
  }
  if (carsNum >= 2)
  {
    for(int i = 0 ; i <= 3 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(1000);
    }
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000 * carsNum);
    carsNum = 0;
    for(int i = 0 ; i <= 3 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(1000);
    }
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  delay(1000);
}
void buttonPressed() {
  // This function is called when the button is pressed
    for(int i = 0 ; i <= 3 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(1000);
    }
    delay(2000);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW); 
    digitalWrite(RED_LED, HIGH);
    delay(5000);
}