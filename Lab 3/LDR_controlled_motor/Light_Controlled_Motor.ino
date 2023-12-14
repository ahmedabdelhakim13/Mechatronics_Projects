//              THE SIMULATION LINK ON TINKERCAD
//https://www.tinkercad.com/things/6acqqqypZAs-lab3?sharecode=0-9Kpq8cVF5yPpngqr2RUf48aAp1lEKc42seEivhU0E

#define POT              A0   // Analog input pin for the potentiometer.
#define LDR              A1   // Analog input pin for the LDR.
#define LED              6    // LED pin.
#define BUTTON_CASE_2    2    // push button pin for cases.
#define BUTTON_CASE_3    4    // push button pin for cases.

#define MOTOR_PIN_1 8
#define MOTOR_PIN_2 9
#define MOTOR_SPEED_CONTROL_PIN 3


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
  pinMode(LED  , OUTPUT );           // LED as output.

  pinMode(MOTOR_SPEED_CONTROL_PIN,OUTPUT); // to control the speed of the motor
  pinMode(MOTOR_PIN_1,OUTPUT); //input2
  pinMode(MOTOR_PIN_2,OUTPUT); //input1

  Serial.begin(9600);
}

void loop()
{		digitalWrite( LED , HIGH );
                           /* For first task don't press on any buttons.*/
      /***********    first task is about motor is on when light intensity is high and it is off when light intensity is low   ***********/
   if( digitalRead(BUTTON_CASE_2) == LOW && digitalRead(BUTTON_CASE_3) == LOW) 
   {
    
    // Turn on LED.
    digitalWrite( LED , HIGH );
    delay(50);

    // Read the LDR value (0-1023).
    LDR_Value = analogRead(LDR); 

    // If the value read is less than the threshold then the motor is on, else the motor is off. 
    // when light intensity increase the value of the LDR decreases
      if( LDR_Value <= 500 )  // ldr value is small below our own set threshold which means light intensity is high 
      {
         digitalWrite(MOTOR_SPEED_CONTROL_PIN,HIGH);
         digitalWrite(MOTOR_PIN_1,HIGH);
         digitalWrite(MOTOR_PIN_2,LOW);
         
      } 
      else  // ldr value is high over our own set threshold which means light intensity is low
      {
         digitalWrite(MOTOR_SPEED_CONTROL_PIN,LOW);
      }

    delay(5000); 

    // Turn off LED.
    digitalWrite( LED , LOW );
    delay(50);


   }

                                              /* For second task press on first button.*/

                          /* The same as previous except if the led is on the motor stops else the motor rotates. */
      /***********   second task is about motor is off when light intensity is high and it is on when light intensity is low   ***********/

   else if( digitalRead(BUTTON_CASE_2) == HIGH && digitalRead(BUTTON_CASE_3) == LOW)
   {
     
    digitalWrite( LED , HIGH );
    delay(50);

    LDR_Value = analogRead(LDR); 

    // If the value read is more than the threshold then the motor is on, else the motor is off. 

      if( LDR_Value >= 500 )    // ldr value is high over our own set threshold which means light intensity is low
      {
         digitalWrite(MOTOR_SPEED_CONTROL_PIN,HIGH);
         digitalWrite(MOTOR_PIN_1,HIGH);
         digitalWrite(MOTOR_PIN_2,LOW);
      } 
      else    // ldr value is small below our own set threshold which means light intensity is high
      {
         digitalWrite(MOTOR_SPEED_CONTROL_PIN,LOW);
      }

    delay(5000); 
    
    digitalWrite( LED , LOW );
    delay(50);

    
   }

                           /*For third task press on the two buttons.*/

  else if( digitalRead(BUTTON_CASE_2)== LOW && digitalRead(BUTTON_CASE_3) == HIGH)
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
      digitalWrite(MOTOR_SPEED_CONTROL_PIN,MotorSpeed);
      digitalWrite(MOTOR_PIN_1,HIGH);
      digitalWrite(MOTOR_PIN_2,LOW);

  }

}



