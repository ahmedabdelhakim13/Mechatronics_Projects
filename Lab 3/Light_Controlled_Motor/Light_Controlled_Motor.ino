// Simulation Link: https://www.tinkercad.com/things/hyklOp6Vsdd-task-3-light-controlled-motor
#define POT              0   // Analog input pin for the potentiometer.
#define LDR              1   // Analog input pin for the LDR.
#define LED              6    // LED pin.
#define BUTTON_CASE_2    2    // push button pin for cases.
#define BUTTON_CASE_3    3		// push button pin for cases.
#define VALUE            100

#define MOTOR			       9

bool case2 = false;
bool case3 = false;

int LED_Intensity = 0; // Initialize Led intensity.
int PotValue      = 0; // Initialize Potentiometer value.
int LDR_Value     = 0; // Initialize LDR value.
int MotorSpeed    = 0; // Initialize Motor speed.

void setup() {
  Serial.begin(9600);

  pinMode(POT , INPUT );             // Potentiometer as input.
  pinMode(LDR , INPUT );             // LDR as input.
  pinMode(BUTTON_CASE_2 , INPUT );   // Push button  as input.
  pinMode(BUTTON_CASE_3 , INPUT );   // Potentiometer as input.
  pinMode(LED  , OUTPUT );           // LED as output.

  pinMode(MOTOR, OUTPUT); //input1

  attachInterrupt(digitalPinToInterrupt(BUTTON_CASE_2), case2Control, RISING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_CASE_3), case3Control, RISING);
}

void loop() 
{
  digitalWrite( LED , HIGH );
                           /* For first task don't press on any buttons.*/
      /***********    first task is about motor is on when light intensity is high and it is off when light intensity is low   ***********/
    
    // Turn on LED.
    digitalWrite( LED , HIGH );
    delay(50);

    // Read the LDR value (0-1023).
    LDR_Value = analogRead(LDR); 

    // If the value read is less than the threshold then the motor is on, else the motor is off. 
    // when light intensity increase the value of the LDR decreases
      if( LDR_Value <= VALUE )  // ldr value is small below our own set threshold which means light intensity is high 
      {
         digitalWrite(MOTOR, HIGH);
         
      } 
      else  // ldr value is high over our own set threshold which means light intensity is low
      {
         digitalWrite(MOTOR, LOW);
      }


    // Turn off LED.
    digitalWrite(LED , LOW);
    delay(50);
                                                /* For second task press on first button.*/

                          /* The same as previous except if the led is on the motor stops else the motor rotates. */
      /***********   second task is about motor is off when light intensity is high and it is on when light intensity is low   ***********/
  while(case2)
  {
    digitalWrite( LED , HIGH );
    delay(50);

    LDR_Value = analogRead(LDR); 

    // If the value read is more than the threshold then the motor is on, else the motor is off. 

      if( LDR_Value >= VALUE )    // ldr value is high over our own set threshold which means light intensity is low
      {
         digitalWrite(MOTOR, HIGH);
      }
      else    // ldr value is small below our own set threshold which means light intensity is high
      {
         digitalWrite(MOTOR, LOW);
      }

    
    digitalWrite( LED , LOW );
    delay(50);
  }

  while(case3)
  {
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
      analogWrite(MOTOR, MotorSpeed);
  }

}

void case2Control()
{
  case3 = false;
  case2 = !(case2);
}

void case3Control()
{
  case2 = false;
  case3 = !(case3);
}