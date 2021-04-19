#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 5     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
    // start working...  Serial.println("=================================");
  delay(2000);
  Serial.println("DHT11...");
}

void loop() {

  
  // read without samples.
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t)||isnan(h)) {    
    Serial.println("Failed to read from DHT sensor!");
  }
  else {
    Serial.print(t);Serial.print(" *C, "); 
    Serial.print(h);Serial.println(" % ");
  }
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
