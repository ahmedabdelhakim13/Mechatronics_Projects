// Simulation Link: https://www.tinkercad.com/things/53bQQgakQAL


#define PEDESTRIANBUTTON  2
#define CARSBUTTON        3
#define RED_LED           8
#define YELLOW_LED        9
#define GREEN_LED         10
#define BUZZER            A1
#define BlinkingTime      1000
#define CarTime           3000
#define Repeat            1000
#define CARS_LIMIT        1  

unsigned int carsNum = 0;
void pedestrianMode();

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PEDESTRIANBUTTON, INPUT);
  pinMode(CARSBUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(CARSBUTTON), carsButtonPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(PEDESTRIANBUTTON), pedestrianButtonPressed, RISING);
}

void loop()
{
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  unsigned int iteration = 1;
  while(carsNum >= CARS_LIMIT)
  {
    if (iteration == 1)
    {
      for(int i = 0 ; i <= 3 ; i++) /*we blink the yellow led for 4 seconds*/
      {
        digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));  /* some sort of blinking */
        delay(BlinkingTime);
      }
    }
    iteration++;
    // Turn off RED and Yellow LEDS.
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    // Turn on Green LED and activate buzzer.
    tone( BUZZER , 1000 );
    digitalWrite(GREEN_LED, HIGH);
    
    // Delay for a time proportional to the number of cars counted
    delay(CarTime);
    carsNum--;
    if (carsNum == 0)
    {
      for(int i = 0 ; i <= 3 ; i++) /*we blink the yellow led for 4 seconds*/
        {
          digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));  /* some sort of blinking */
          delay(BlinkingTime);
        }
      // Turn off Green and Yellow LEDS and buzzer.
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      noTone( BUZZER );
    }
  }  
  
  // Regular delay before repeating the loop
  delay(Repeat);
}

void carsButtonPressed()
{
  carsNum++;
}

void pedestrianButtonPressed()
{
  pedestrianMode();
}

void pedestrianMode()
{
  if (digitalRead(GREEN_LED)) // This function is called when the button is pressed
  {  
    for(int i = 0 ; i <= 3 ; i++)
    {
      // Alternate the yellow LED when the button is pressed
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(BlinkingTime);
    }
    
    // Add a longer delay to create a pause
    delay(2000);
    
    // Turn off the yellow LED, green LED, and buzzer, and turn on the red LED
    noTone( BUZZER );  
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  // Delay for 5 seconds
    delay(5000);
}