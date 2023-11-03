//Simulation Link: https://www.tinkercad.com/things/fVdycqacZtU

#define MOTOR       9   // The pin number connected to the motor
#define ACC_DELAY   20  // Delay between each speed increment (in milliseconds)
      
const int maxSpeed = 255;    // Maximum speed value (0-255)
const int targetSpeed = 0.6 * maxSpeed;  // Target speed at 0.6 of the maximum speed 

int currentSpeed = 0;         // Current speed of the motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Gradually increase the speed until it reaches the target speed
  if (currentSpeed < targetSpeed) {
    currentSpeed++;
    analogWrite(MOTOR, currentSpeed);
    delay(ACC_DELAY);
  }
  
  // Maintain the constant speed
  if (currentSpeed >= targetSpeed) {
    analogWrite(MOTOR, targetSpeed);
  }
}