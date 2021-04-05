/* RC Circuit experiment sketch. 
 
Connect the positive end of the capacitor to Analog 0.
Then connect power supply to the power headers of the RC circuit.  
For more information see www.atommann.com/learn/rc-circuit/rc-circuit.html */
 
int capPin = 36;      // the positive end of capacitor is connected to a0
int capvoltReading;  // the analog reading from a0
unsigned long rctime;
float t[250], v[250];
const float vlimit = 3.3;
int cnt = 0;
void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(115200);   
  cnt = 0;
}
void sendout()
{
  for(int i=0; i<cnt; i++){
    //prints time since program started
    Serial.print(t[i]); // in seconds
    Serial.print(", ");
    Serial.println(v[i]); // print out the voltage 
  }
}

void loop() {
  rctime = millis();
  capvoltReading = analogRead(capPin); // getting the voltage reading from capacitor
  
  // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = capvoltReading * vlimit;
  voltage /= 4096.0;
  t[cnt]=rctime/1000;
  v[cnt]= voltage;
  //prints time since program started
  Serial.print(rctime/1000); // in seconds
  //Serial.print("0:");
  Serial.print(", ");      // we output data with CSV format
  Serial.println(voltage); // print out the voltage
  cnt = cnt +1;
  if(voltage >= vlimit || cnt>248){
    sendout();
    while(1);
  }
  delay(1000); // 1000ms
}
