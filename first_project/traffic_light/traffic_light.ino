// C++ code
//
#define cars 3
#define traffic_delay 5000

#define LED_Red        13
#define LED_Yellow     12
#define LED_Green      11

#define car_1          8
#define car_2          7
#define car_3          6


void setup()
{
  Serial.begin(9600);
  pinMode(car_1, INPUT);
  pinMode(car_2, INPUT);
  pinMode(car_3, INPUT);
  
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_Green, OUTPUT);
}
//(car_1==LOW)&&(car_2==HIGH)||(car_1==HIGH)&&(car_3==HIGH)||(car_3==HIGH)&&(car_2==HIGH)
void loop()
{
  digitalWrite(LED_Red,HIGH);
  Serial.println(car_1);
  if(car_1==LOW)
  {
    digitalWrite(LED_Green,HIGH);
    delay(traffic_delay);
    digitalWrite(LED_Green,LOW);
    digitalWrite(LED_Yellow,HIGH);
    delay(0.5*traffic_delay);
    digitalWrite(LED_Yellow,LOW);
  }
}