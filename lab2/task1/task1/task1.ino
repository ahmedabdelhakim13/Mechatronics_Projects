
#define pot A0 
#define Motor 12 
#define fullspeed 255
void setup()
{
  pinMode(pot, INPUT);
  pinMode(Motor, OUTPUT);
}

void loop()
{
  int reading = analogRead(pot);
  map(reading,0,1023,0,0.6*fullspeed);
  digitalWrite(Motor, reading);
}