// Simulation link: https://www.tinkercad.com/things/5isKJcbButC

// Define pin numbers for components
#define RED_LED     8
#define YELLOW_LED  9
#define GREEN_LED   10
#define BUTTON      2
#define BUZZER      12
#define PRESSURE    0

unsigned int carsNum = 0;

void setup() 
{
  // Set pin modes for components
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  
  // Attach an interrupt to the button press event
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
  
  // Count cars based on pressure sensor reading
  if (value > 200)
  {
    carsNum++;
  }
  
  // Check if carsNum exceeds 2
  if (carsNum >= 2)
  {
    // Blink the yellow LED and activate the buzzer
    for(int i = 0 ; i <= 3 ; i++)
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
      delay(1000);
    }
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    
    // Delay for a time proportional to the number of cars counted
    delay(1000 * carsNum);
    carsNum = 0;
    
    // Blink the yellow LED and reset the lights
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
  
  // Regular delay before repeating the loop
  delay(1000);
}

void buttonPressed() {
  // This function is called when the button is pressed
  for(int i = 0 ; i <= 3 ; i++)
  {
    // Alternate the yellow LED when the button is pressed
    digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));
    delay(1000);
  }
  
  // Add a longer delay to create a pause
  delay(2000);
  
  // Turn off the yellow LED, green LED, and buzzer, and turn on the red LED
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW); 
  digitalWrite(RED_LED, HIGH);
  
  // Delay for 5 seconds
  delay(5000);
}
