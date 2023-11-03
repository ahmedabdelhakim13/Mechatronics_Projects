// Simulation Link: https://www.tinkercad.com/things/45253GtPiRw

#define POT       0   // Analog input pin for the potentiometer
#define MOTOR     9   // Motor control pin (connected to the transistor)

int motorSpeed = 0; // Initialize motor speed

void setup() 
{
  pinMode(POT, INPUT);
  pinMode(MOTOR, OUTPUT);
}

void loop()
{
  int potValue = analogRead(POT); // Read the potentiometer value (0-1023)

  // Map the potentiometer value to a PWM range (0-255)
  motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Control the motor speed
  analogWrite(MOTOR, motorSpeed);
}