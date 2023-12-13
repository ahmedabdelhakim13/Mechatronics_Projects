#define LDR A0
#define motor_pin 3
#define led 5
float value=0.0;
float volt=0.0;

void setup() {
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  pinMode(Led,OUTPUT);
  pinMode(motor_pin,OUTPUT);
}

void loop() {
  value=analogRead(LDR);
  Serial.println(value);
  delay(500);
  if(value)
  digitalWrite(led,HIGH);
  delay(300);
  volt=(value/1023)*5;
  if(volt)
  {
    if(volt>=4)
    speed1()

    else if(volt>=3)
    Speed2()
    else if(volt>=2)
    speed3()
    else if(volt>=1)
    speed4()
    else
    speed5()
  }
  // put your main code here, to run repeatedly:

}
//defining function 
void speed1()
  {
      analogWrite(motor_pin,256);
      delay(1000);
    }
void speed2()
    {
      analogWrite(motor_pin,205);
      delay(1000);
    }
    void speed3()
    {
      analogWrite(motor_pin,153);
      delay(1000);
    }
    void speed4()
    {
      analogWrite(motor_pin,102);
      delay(1000);
    }
    void speed5()
    {
      analogWrite(motor_pin,51);
      delay(1000);
    }