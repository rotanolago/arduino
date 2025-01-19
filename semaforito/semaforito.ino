/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

// constants won't change. Used here to set a pin number:
const int ledPin = LED_BUILTIN;  // the number of the LED pin
int currentPin = 1;

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 750;  // interval at which to blink (milliseconds)


int redPin = 8;
int greenPin = 9;
int bluePin = 10;

void setup() {  
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);

  pinMode(6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  delay(500);

  byte buttonState = digitalRead(6);
  
    if (buttonState == LOW) {
      currentPin = currentPin + 1;
      if(currentPin ==5){
        currentPin = 1;
      }
        Serial.println(currentPin);
    }
    else {
        Serial.println("Button is not pressed");
    }
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    digitalWrite(currentPin, LOW);
    
    digitalWrite(currentPin, HIGH);
    
    if(currentPin == 2){
      digitalWrite(redPin, HIGH);
    } else if(currentPin == 3){
      digitalWrite(greenPin, HIGH);
      analogWrite(currentPin, 10);
    } else if(currentPin == 4){
      digitalWrite(bluePin, HIGH);
    } else {
        
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);

      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
    }

    digitalWrite(currentPin, HIGH);

}
