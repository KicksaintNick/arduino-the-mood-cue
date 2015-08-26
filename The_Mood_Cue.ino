// We need to include the Servo library since we're using a servo in this sketch
#include <Servo.h> 

// We need to create a servo instance and set a pin to be used by the Servo
Servo deciderServo;
const int servoPin = 9;

// We also need to define some variables that will be used to operate the potentiometer
const int potPin = A0; // We connect the potentiometer to analog pin A0
int potValue; // This will store the value from the potentiometer when we rotate it
int angle; // This variable will store the converted potentiometer value in degrees

// Setup functionality
void setup() {
  deciderServo.attach(servoPin); // The servo gets attached to the servo pin defined
  Serial.begin(9600); // In order for us to debug the potValue and angle variables we connect the Serial monitor on BAUD 9600
}

// Loop functionality
void loop() {
  // The first thing we need to do is read the value from the potentiometer
  potValue = analogRead(potPin); // We use the analogRead function passing in the pin for the potentiometer

  // We then print this value out to Serial so we can see it in the Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);

  // Next we use the map function to convert the potentiometer value into degrees
  // The map function scales numbers doing all the heavy lifting for you converting
  // any value between 0 and 1024 to a value between 0 and 180
  // We store this value in our angle variable which will be used to control the servo
  // Read more about the map function here: https://www.arduino.cc/en/Reference/Map
  angle = map(potValue, 0, 1024, 0, 180);

  // We then print the angle to the Serial Monitor
  Serial.print(", Servo angle: ");
  Serial.println(angle);

  // We write the angle value to the servo using the write function
  // the write function accepts a value in degrees and angle is a degrees value
  // Read more about the Servo library here: https://www.arduino.cc/en/Reference/Servo
  deciderServo.write(angle);

  // Lastly we need to delay the loop function by a few milliseconds to give
  // the servo a chance to complete its physical movement. I'd suggest playing 
  // with this value a bit, it will give you an idea of why this is necessary
  delay(20);
}
