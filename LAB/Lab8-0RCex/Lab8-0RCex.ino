/* RC Circuit experiment sketch. 
 
Connect the positive end of the capacitor to Analog 0.
Then connect power supply to the power headers of the RC circuit.  
For more information see www.atommann.com/learn/rc-circuit/rc-circuit.html */
 
int capPin = 36;      // the positive end of capacitor is connected to a0
int capvoltReading;  // the analog reading from a0
unsigned long rctime;

void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(115200);   
}
 
void loop() {
  rctime = millis();
  capvoltReading = analogRead(capPin); // getting the voltage reading from capacitor
  
  // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = capvoltReading * 3.3;
  voltage /= 4096.0;
 
  //prints time since program started
  Serial.print(rctime/1000); // in seconds
  //Serial.print("0:");
  Serial.print(", ");      // we output data with CSV format
  Serial.println(voltage); // print out the voltage
 
  delay(1000); // 1000ms
}
