										                                    /* MACROS */  
                                                        
#define min_distance 20                                                        
#define SPEED        150
#define TRIG_PIN     12
#define ECHO_PIN     11
#define motor1Pin1   10  
#define motor1Pin2   9
#define motor1EN     A0
#define motor2Pin1   8
#define motor2Pin2   7
#define motor2EN     A1

									                                   	/* Intializing Variables */
						
float duration_us = 0 ;
float distance    = 0 ;

void setup() 
{
	
  Serial.begin(9600)      	 ;    // For serial monitoring.
  intializeMotion()		       ;	  // Function to set pin directions of the motors for motion.	
  speedMotion(SPEED)		     ;	  // Function that makes the motors run at constant speed. 
  pinMode(TRIG_PIN, OUTPUT)	 ;    // Making Trigger pin of ultrasonic sensor as output.  
  pinMode(ECHO_PIN, INPUT)   ;    // Making Echo pin of ultrasonic sensor as output.
  
 }

                                      /*   Main Code  */
void loop() {
	
	UltrasonicCalculations();     // Function that makes all calculations required for Ultrasonic sensor. 
  
         /* If the distance between the ultrasonic sensor and an obstacle is larger than 20cm move forward else stop then move backward then stop then move to the left. */

    if (distance > min_distance)           
	{
		forwardMotion()		;
	}
   
   else
	{
		stopMotion()		;
		delay(500)			;
		backwardMotion()	;
		delay(500)			;
		stopMotion()		;
		delay(500)			;  
		leftMotion()		;  
		delay(500)			; 
	
	}


}
                                                    
                                                              /*  Used functions impelementation.  */

void intializeMotion()    // Function to define pins direction for the motors.
{
	
  pinMode(motor1Pin1,OUTPUT); 
  pinMode(motor1Pin2,OUTPUT);
  pinMode(motor1EN,OUTPUT)	;
  pinMode(motor2Pin1,OUTPUT);
  pinMode(motor2Pin2,OUTPUT);
  pinMode(motor2EN,OUTPUT)	;

}

void speedMotion(int speedPWM)   // Giving the motors the same speed.
{
  analogWrite(motor1EN,speedPWM);
  analogWrite(motor2EN,speedPWM);
}

void forwardMotion()           // Moving Forward.
{
	
  digitalWrite(motor1Pin1,HIGH)	;
  digitalWrite(motor1Pin2,LOW)	;
  digitalWrite(motor2Pin1,HIGH)	;
  digitalWrite(motor2Pin2,LOW)	;

}

void backwardMotion()        // Moving Backward.
{
	
  digitalWrite(motor1Pin1,LOW)	;
  digitalWrite(motor1Pin2,HIGH)	;
  digitalWrite(motor2Pin1,LOW)	;
  digitalWrite(motor2Pin2,HIGH)	;	
  
}

void leftMotion()           // Moving Left about center of gravitiy (Not rotating around a fixed wheel).
{
	
  digitalWrite(motor1Pin1,HIGH)	;
  digitalWrite(motor1Pin2,LOW)	;
  digitalWrite(motor2Pin2,HIGH)	;
  digitalWrite(motor2Pin1,LOW)	;
  
}

void stopMotion()          // STOP.
{
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,LOW);
}


void UltrasonicCalculations()   // Calculations of the ultrasonic sensor.
{
	
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us = pulseIn(ECHO_PIN, HIGH);
  
  distance = 0.017 * duration_us; // Converting the duration into distance.(Distance= 0.5 X Speed of Sound X time .)
  
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
}