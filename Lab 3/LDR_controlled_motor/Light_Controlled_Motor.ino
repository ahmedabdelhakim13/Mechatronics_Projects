#define POT              A0   // Analog input pin for the potentiometer.
#define LDR              A1   // Analog input pin for the LDR.
#define MOTOR            9    // Motor control pin (connected to the transistor).
#define LED              6    // LED pin.
#define BUTTON_CASE_2    2    // push button pin for cases.
#define BUTTON_CASE_3    4    // push button pin for cases.

int LED_Intensity = 0; // Initialize Led intensity.
int PotValue      = 0; // Initialize Potentiometer value.
int LDR_Value     = 0; // Initialize LDR value.
int MotorSpeed    = 0; // Initialize Motor speed.

void setup() 
{
  pinMode(POT , INPUT );             // Potentiometer as input.
  pinMode(LDR , INPUT );             // LDR as input.
  pinMode(BUTTON_CASE_2 , INPUT );   // Push button  as input.
  pinMode(BUTTON_CASE_3 , INPUT );   // Potentiometer as input.
  pinMode(MOTOR , OUTPUT );          // Motor as output.
  pinMode(LED  , OUTPUT );           // LED as output.
}

void loop()
{
                           /* For first task don't press on any buttons.*/

   if( BUTTON_CASE_2 == LOW && BUTTON_CASE_3 == LOW) 
   {
    
    // Turn on LED.
    digitalWrite( LED , HIGH );
    delay(50);

    // Read the LDR value (0-1023).
    LDR_Value = analogRead(LDR); 

    // If the value read is less than the threshold then the motor is off, else the motor is on. 
      if( LDR_Value <= 500 )
      {
        digitalWrite( MOTOR , LOW );
      } 
      else
      {
        digitalWrite( MOTOR , HIGH );
      }

    delay(5000); 

    // Turn on LED.
    digitalWrite( LED , LOW );
    delay(50);

    // Read the LDR value (0-1023).
    LDR_Value = analogRead(LDR);

    // If the value read is less than the threshold then the motor is off, else the motor is on.
    if( LDR_Value >= 500 )
      {
        digitalWrite( MOTOR , HIGH );
      } 
     else
      {
        digitalWrite( MOTOR , LOW );
      }

     delay(5000); 
   }

                                              /* For second task press on first button.*/

                          /* The same as previous except if the led is on the motor stops else the motor rotates. */

   else if( BUTTON_CASE_2 == HIGH && BUTTON_CASE_3 == LOW)
   {
     
    digitalWrite( LED , HIGH );
    delay(50);

    LDR_Value = analogRead(LDR); 

      if( LDR_Value <= 500 )
      {
        digitalWrite( MOTOR , HIGH );
      } 
      else
      {
        digitalWrite( MOTOR , LOW );
      }

    delay(5000); 
    
    digitalWrite( LED , LOW );
    delay(50);

    LDR_Value = analogRead(LDR);

    if( LDR_Value >= 500 )
      {
        digitalWrite( MOTOR , LOW );
      } 
    else
      {
        digitalWrite( MOTOR , HIGH );
      }  

     delay(5000); 
   }

                           /*For third task press on the two buttons.*/

  else if( BUTTON_CASE_2 == HIGH && BUTTON_CASE_3 == HIGH)
   {
      // Read the potentiometer value (0-1023).
      PotValue = analogRead(POT); 

      // Map the potentiometer value to a PWM range (0-255).
      LED_Intensity = map(PotValue, 0, 1023, 0, 255);

      // Control the Led intensity according to potentiometer value.
      analogWrite(LED, LED_Intensity);

      // Read the LDR value (0-1023).
      LDR_Value = analogRead(LDR); 
      delay(50);

      // Map the LDR value to a PWM range (0-255).
      MotorSpeed = map(LDR_Value , 0 , 1023 , 0 , 255 );

      // Control the speed of the motor according to LDR value which depends on LED intensity controlled bypotentiometer.
      analogWrite( MOTOR , MotorSpeed );

  }

}