#define LDR A0
#define motor_pin 3
#define led 5
#define pot 7
#define st 8
#define push1 9
#define push2 10
/////////////////////////////////////////////////////////////////////////////////////////
int start=0; 
int stat1=0;
int stat2=0;
int Ldr_value=0;
int speed=0;
int pot_value=0;
///////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  pinMode(st,INPUT);
  pinMode(push1,INPUT);
  pinMode(push2,INPUT);
  pinMode(led,OUTPUT);
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
    digitalWrite(motor_pin,200);
    delay(2000);
    }
    else if(!start)
    {
    digitalWrite(led ,LOW);
    digitalWrite(motor_pin,0);
    delay(2000);

    }

  }
  void func2()
  {
    if(start)
  {
    digitalWrite(led ,LOW);
    //speed =map(Ldr_value,0,1023,0,286);
    digitalWrite(motor_pin,200);
    delay(2000);
  }
  else if(!start)
    {
    digitalWrite(led ,HIGH);
    digitalWrite(motor_pin,0);
    delay(2000);

    }
}
void func3()
{
  if(start)
  {
    PotValue = analogRead(POT);
    
    digitalWrite(led ,LOW);
    //speed =map(Ldr_value,0,1023,0,286);
    digitalWrite(motor_pin,200);
    delay(2000);
    
  }

}
