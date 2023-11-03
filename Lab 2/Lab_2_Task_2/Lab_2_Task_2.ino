//Simulation Link: https://www.tinkercad.com/things/k4JWvAlLA3x

#define MOTOR_PIN_1 8
#define MOTOR_PIN_2 9
#define MOTOR_SPEED_CONTROL_PIN 3

void rotate_cw();
void rotate_ccw();

void setup() {
  
  pinMode(MOTOR_SPEED_CONTROL_PIN,OUTPUT); // to control the speed of the motor
  pinMode(MOTOR_PIN_1,OUTPUT); //input2
  pinMode(MOTOR_PIN_2,OUTPUT); //input1
}

void loop()
{
  rotate_cw();
  delay(4000);
  rotate_ccw();
  delay(4000);
}
void rotate_cw()
{
   digitalWrite(MOTOR_SPEED_CONTROL_PIN,HIGH);
   digitalWrite(MOTOR_PIN_1,HIGH);
   digitalWrite(MOTOR_PIN_2,LOW);
}

void rotate_ccw()
{
   digitalWrite(MOTOR_SPEED_CONTROL_PIN,HIGH);
   digitalWrite(MOTOR_PIN_1,LOW);
   digitalWrite(MOTOR_PIN_2,HIGH);
}