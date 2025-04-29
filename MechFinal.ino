//include commands
#include <SR04.h>
#include <Servo.h>
#include <Servo.h> 
#include "IRremote.h"
#include "IR.h"
Servo POSservo;
//Servos, censors, cutoffs
int L_CAL = 91;
int R_CAL = 90;
int L_servo_pin = 7;
int R_servo_pin = 8;
int IR_pin = 6;  
int servoPin = 2;
int pos = 0;   
Servo RIGHTservo;
Servo LEFTservo;
int servo_offset = 5;
int oneeightyspin = 8000;
IRrecv irrecv(IR_pin);     
decode_results results;  
int TRIG_PIN = 9;
int ECHO_PIN = 13;
int QRE_L=0;
int QRE_C=1;
int QRE_R=3;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long DistanceValue;
int VALUE_L;
int VALUE_C;
int VALUE_R;
int CUTOFF_L = 700; 
int CUTOFF_C = 700; 
int CUTOFF_R = 700; 

void setup() {
Serial.begin(9600);
RIGHTservo.attach(R_servo_pin);
LEFTservo.attach(L_servo_pin);
POSservo.attach(servoPin);
LEFTservo.write(L_CAL);
RIGHTservo.write(R_CAL);
delay(2000);
}

void loop() {
VALUE_L = analogRead(QRE_L); 
VALUE_C = analogRead(QRE_C);
VALUE_R = analogRead(QRE_R);
DistanceValue = sr04.Distance();
Serial.print( DistanceValue);
Serial.println(  VALUE_L  );
Serial.println(  VALUE_C  );
Serial.println(  VALUE_R  );


if (DistanceValue <= 15)
{
    LEFTservo.write(L_CAL);
    RIGHTservo.write(R_CAL);
    POSservo.write(90);
    Serial.println(" Dispense");
    delay(5000);
    POSservo.write(0);
    delay(1000);
    LEFTservo.write(L_CAL-servo_offset);
    RIGHTservo.write(R_CAL-servo_offset);
    delay(oneeightyspin);
  } 
  else if (VALUE_L < CUTOFF_L && VALUE_R > CUTOFF_R)
  {
    Serial.println("   TURNING RIGHT");
    LEFTservo.write(L_CAL+18);
    RIGHTservo.write(R_CAL+18);
    delay(300);
  }
  else if (VALUE_L > CUTOFF_L && VALUE_R < CUTOFF_R)
  {
    Serial.println("  TURNING LEFT");
    LEFTservo.write(L_CAL-18);
    RIGHTservo.write(R_CAL-18);
    delay(300);
  }


else
Serial.println("  Forward");
LEFTservo.write(L_CAL+4);
RIGHTservo.write(R_CAL-5);
delay(750);
}



