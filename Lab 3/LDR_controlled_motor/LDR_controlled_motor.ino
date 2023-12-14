#define LDR A0
#define motor_pin 3
#define led 5
#define pot 7
#define start 8
#define push1 9
#define push1 10
/////////////////////////////////////////////////////////////////////////////////////////
int start=0; 
int stat1=0;
int stat2=0;
int Ldr_value=0;
int speed=0;
///////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  pinMOde(start,INPUT)
  pinMOde(push1,INPUT)
  pinMOde(push2,INPUT)
  pinMode(Led,OUTPUT);
  pinMode(LDR,OUTPUT);
  pinMode(motor_pin,OUTPUT);
}

void loop() {
  start = digitalRead(start);
  stat1 = digitalRead(push1);
  stat2 = digitalRead(push2);

  if((stat1==1)&&(stat2==0))
    func1();

  if(((stat1==0)&&(stat2==1)))
    func2();

  if(((stat1==1)&&(stat2==1)))
    func3();

  }
  
}
///////////////////////////////////////////////////////////////
void func1()
{
  if(start)
  {
    digitalWrite(led ,HIGH);
    Ldr_value = analogRead(LDR);
    if(Ldr_value>300)
    {
    digitalWrite(motor_pin,200);
    delay(2000);
    }
  }
  void func2()
  {
    if(start)
  {
    digitalWrite(led ,LOW);
    Ldr_value = analogRead(LDR);
    //speed =map(Ldr_value,0,1023,0,286);
    if(Ldr_value>300)
    {
    digitalWrite(motor_pin,200);
    delay(2000);
    }
  }
}
