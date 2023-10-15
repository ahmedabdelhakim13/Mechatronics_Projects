// Simulation link: https://www.tinkercad.com/things/5isKJcbButC

                           /* MACROS */

                      // Define pin numbers for components.

#define RED_LED           8
#define YELLOW_LED        9
#define GREEN_LED        10
#define BUTTON            2
#define BUZZER           A1
#define PRESSURE         A0
#define BlinkingTime    1000
#define CarTime         3000
#define Repeat          1000
#define CARS_LIMIT      2    /* this is the limit number of cars afterwhich our program get triggered and the green led lightens up */
                      
                      //Variable stores the number of cars.

unsigned int carsNum = 0;

                       /* Set pin modes for components.  */
void setup() 
{
                         // Basic components.                             
  
  // LEDS as output and pressure sensor as input.
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PRESSURE, INPUT);
  
                        // Added Features.
  // Attach an interrupt to the button press event.
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, RISING);
  pinMode(BUZZER, OUTPUT);      /* we used a buzzer as a source of sound to help the blind people */
  pinMode(BUTTON, INPUT);
}
                       
void loop() 
{
  //Turn on RED LED and Turn off all other LEDS and buzzer.
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);  
  noTone( BUZZER );
  
  //Taking the reading of the pressure sensor.
  int value = analogRead(PRESSURE);       /* we loop on the reading of the pressure sensor so we can detect whenever the user touches the sensor */
  
  // Count cars based on pressure sensor reading.
  if (value > 200)
  {
    carsNum++;
  }
  
  // Check if carsNum exceeds 2.
  if (carsNum >= CARS_LIMIT)
  {
    // Blink the yellow LED and activate the buzzer.
    for(int i = 0 ; i <= 3 ; i++) /*we blink the yellow led for 4 seconds*/
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));  /* some sort of blinking */
      delay(BlinkingTime);
    }
    
    // Turn off RED and Yellow LEDS.
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    // Turn on Green LED and activate buzzer.
    tone( BUZZER , 1000 );
    digitalWrite(GREEN_LED, HIGH);
    
    // Delay for a time proportional to the number of cars counted
    delay(CarTime * carsNum);
    // Reset number of cars after all cars passes. 
    carsNum = 0;
   
    // Blink the yellow LED and reset the lights
    for(int i = 0 ; i <= 3 ; i++) /*we blink the yellow led for 4 seconds*/
    {
      digitalWrite(YELLOW_LED, !(digitalRead(YELLOW_LED)));  /* some sort of blinking */
      delay(BlinkingTime);
    }
    // Turn off Green and Yellow LEDS and buzzer.
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    noTone( BUZZER );
    //Turn on Red LED.
    digitalWrite(RED_LED, HIGH);
  }
  
  // Regular delay before repeating the loop
  delay(Repeat);
}

void buttonPressed() {
  // This function is called when the button is pressed
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
  
  // Delay for 5 seconds
  delay(5000);
}
