/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 17 has a pushbutton attached to it. Give it a name:
int dipsw1 = 18;
int dipsw2 = 19;
int ledPin1 = 14;
int ledPin2 = 12;
int swState1 = 0;
int swState2 = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(dipsw1, INPUT_PULLUP);
  pinMode(dipsw2, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  swState1 = digitalRead(dipsw1);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (swState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }
  
  swState2 = digitalRead(dipsw2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (swState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
  }
  Serial.print(swState1);
  Serial.print(", ");
  Serial.println(swState2);
  delay(300);        // delay in between reads for stability
}
