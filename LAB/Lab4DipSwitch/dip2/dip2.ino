
// digital pin 17 has a pushbutton attached to it. Give it a name:
int dipsw1 = 4;
int dipsw2 = 2;
int swState1 = 0;
int swState2 = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(dipsw1, INPUT);
  pinMode(dipsw2, INPUT);
}

// the loop routine runs over and over again forever:
void loop() { 
  swState1 = digitalRead(dipsw1);
  swState2 = digitalRead(dipsw2);
  Serial.print(swState1);
  Serial.print(", ");
  Serial.println(swState2);
  delay(3000);        // delay in between reads for stability
}
