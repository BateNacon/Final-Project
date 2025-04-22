// TO USE YOU MUST WIRE AS FOLLOWING
// HAVE LEFT SERVO SIGNAL FROM DIGITAL 7
// HAVE RIGHT SERVO SIGNAL FROM DIGITAL 8
// HAVE RGB red pin on DIGITAL 11
// HAVE RGB green pin on DIGITAL 12
// HAVE RGB blue pin on DIGITAL 13

// Get all your motors declared and the speed commands
#include <Servo.h>     // This calls the Servo library to convert a value to a pulse width
Servo RIGHTservo;      // Right Servo is identified by servo library as variable RIGHTservo
Servo LEFTservo;       // Left Servo is identified by servo library as variable LEFTservo

// Set the servo pin values
int L_servo_pin = 7;   // HAVE LEFT SERVO SIGNAL FROM DIGITAL 7
int R_servo_pin = 8;  // HAVE RIGHT SERVO SIGNAL FROM DIGITAL 8

// Set the RGB pin values
int redPin= 11;       // HAVE RGB red pin on DIGITAL 11
int greenPin = 12;    // HAVE RGB green pin on DIGITAL 12
int bluePin = 13;     // HAVE RGB blue pin on DIGITAL 13

// FOR FITEC MOTORS
// need to correct to values for your motors!
int L_CAL = 93;       //the midpoint value that will give a stop 
int R_CAL = 91;       //the midpoint value that will give a stop
int SERVO_OFFSET = 6;//an offset from midpoint that will give a slow wheel turn
int L_SERVO_OFFSET = 4;                             // X_CAL + SERVO_OFFSET will go slowly one direction
                             // X_CAL - SERVO_OFFSET will go slowly the other direction

// need to correct to values that give the correct spin amount
int spin_90 = 2000;
int spin_180 = 3775;

void setup() {
  // set RGB pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // link your servo objects and output pins
  RIGHTservo.attach(R_servo_pin);// Attach the right servo to the Servo Pin 13
  LEFTservo.attach(L_servo_pin);  // Attach the left servo to the Servo Pin 12
  // start the serial port comm
  Serial.begin(9600);
  delay(2000);
}
void loop() {
  //STEP 1 -- 180 spin
  RIGHTservo.write(R_CAL + SERVO_OFFSET); // turn right wheel forward
  LEFTservo.write(L_CAL + L_SERVO_OFFSET); //  turn left wheel forward
  //amount red green blue
  setColor(0, 255, 0); // Green Color
  Serial.println("STEP 1 - RIGHT SPIN");
  delay(spin_180);

  //STEP 2 --Forward
  RIGHTservo.write(R_CAL - SERVO_OFFSET);
  LEFTservo.write(L_CAL + L_SERVO_OFFSET);
  setColor(0, 0, 255); // Blue Color
  delay(spin_90);
  RIGHTservo.write(R_CAL); // turn right wheel forward
  LEFTservo.write(L_CAL); //  turn left wheel forward

  //STEP 3 --Backward
  RIGHTservo.write(R_CAL + SERVO_OFFSET);
  LEFTservo.write(L_CAL - L_SERVO_OFFSET - 4);
  setColor(255, 0, 0); // Red Color
  delay(spin_90);
  RIGHTservo.write(R_CAL); // turn right wheel forward
  LEFTservo.write(L_CAL); //  turn left wheel forward

  println("hi");

    //STEP 4 --Spin
  RIGHTservo.write(R_CAL - SERVO_OFFSET);
  LEFTservo.write(L_CAL - L_SERVO_OFFSET);
  setColor(255, 255, 255); // White Color
  delay(spin_90);
  RIGHTservo.write(R_CAL); // turn right wheel forward
  LEFTservo.write(L_CAL); //  turn left wheel forward

  //STEP 5 --Forward
  RIGHTservo.write(R_CAL - SERVO_OFFSET);
  LEFTservo.write(L_CAL + L_SERVO_OFFSET);
  setColor(0, 0, 255); // Blue Color
  delay(spin_90);
  RIGHTservo.write(R_CAL); // turn right wheel forward
  LEFTservo.write(L_CAL); //  turn left wheel forward

  //STEP 6 --Backward
  RIGHTservo.write(R_CAL + SERVO_OFFSET);
  LEFTservo.write(L_CAL - L_SERVO_OFFSET - 4);
  setColor(255, 0, 0); // Red Color
  delay(1000);
  RIGHTservo.write(R_CAL); // turn right wheel forward
  LEFTservo.write(L_CAL); //  turn left wheel forward
  setColor(10, 10, 10); // Light White Color
  delay(1000);
  
  






/*
  //STEP 4 -- 180 spin
  RIGHTservo.write(R_CAL - SERVO_OFFSET); // turn right wheel forward
  LEFTservo.write(L_CAL - SERVO_OFFSET); //  turn left wheel forward
  //amount red green blue
  setColor(255,  255,  0); // Orange Color
  Serial.println("STEP 4 LEFT SPIN");
  delay(spin_90);

  //STEP 5
  */





  
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
