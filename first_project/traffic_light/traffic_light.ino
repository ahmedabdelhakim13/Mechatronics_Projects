// C++ code
//
<<<<<<< Updated upstream
//------------------------------------------------------------include------------------------------------------------------//
=======
#define cars 3
>>>>>>> Stashed changes
#define traffic_delay 10000

#define LED_Red        13
#define LED_Yellow     12
#define LED_Green      11

#define car_1          8
#define car_2          7
#define car_3          6

#define interrupt      9

//------------------------------------------------------------------setup----------------------------------------------------//
void setup()
{
  Serial.begin(9600);
  pinMode(car_1, INPUT);
  pinMode(car_2, INPUT);
  pinMode(car_3, INPUT);
  pinMode(interrupt, INPUT);
  
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_Green, OUTPUT);
}

//-----------------------------------------------------------------Main----------------------------------------------//
void loop()
{

  byte x;
  byte y;
  byte z;
  x=digitalRead(car_1);
  y=digitalRead(car_2);
  z=digitalRead(car_3);
  
  digitalWrite(LED_Red,HIGH);
  digitalWrite(LED_Green,LOW);
  digitalWrite(LED_Yellow,LOW);


  
  if((x==LOW)&&(y==HIGH)||(x==HIGH)&&(z==HIGH)||(y==HIGH)&&(z==HIGH))
  {
    digitalWrite(LED_Green,HIGH);
    delay(traffic_delay);
    for(int i=0;i<5;i++)
    {
      digitalWrite(LED_Red,LOW);
    digitalWrite(LED_Green,LOW);
    digitalWrite(LED_Yellow,!(digitalRead(LED_Yellow)));
    delay(0.10*traffic_delay);
    }
  }
}
