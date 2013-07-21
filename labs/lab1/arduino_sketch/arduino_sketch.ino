/*
  C Lab 1 (Not to be confused with Sealab 2021)
  The purpose of this exercise is to build an alert to remind
  somebody that their plant needs watering.
  
  There are two nails that will be used as (analog) sensors
  to read the moisture level in the soil. When that level drops
  below a certain threshold (800, for starters), the LED should
  light.
*/

// Pin 13 is the LED that will be our signal when moisture levels
// in the soil drops too low.
int led = 13;
// Pin A0 is the analog pin connected to one of our nail sensors
int sensorPin = A0;
int sensorValue = 0; // somewhere to store the value
int lastValue = 0; // a variable to compare values


void setup() {
  
  // This is called when the program starts. It
  // basically sets up the board. Put any initialization
  // code here.
  
  // initialize our digital LED pin as output
  pinMode(led, OUTPUT);
  
  // initialize serial communication at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  
  // This is where your main code goes. This function
  // loops over and over, and allows you to respond to
  // input from your sensors. It only stops running when
  // the board is switched off
  
  // read the value from our nail sensor
  sensorValue = analogRead(sensorPin);
  
  // if that value is below 800, light up the LED and write
  // a message
  if (sensorValue < 800) {
    Serial.println("Feed me!");
    digitalWrite(led, HIGH);
    // store the sensor value for later comparison
    lastValue = sensorValue;
  }
  // if the value is close to low, flash the LED
  else if (sensorValue < 850) {
    // flash the LED
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
    lastValue = sensorValue;
  }
  // otherwise,
  else {
    // if this is the first time that the sensor has read
    // a normal reading, write a message
    if (lastValue < 850) {
      Serial.println("Thank you, Seymour!");
    }
    // turn off the LED
    digitalWrite(led, LOW);
    lastValue = sensorValue;
  }
}
