#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
//pls use sketch/include library/manage library find simpledht by winlin 
//or you can use another library
#include <SimpleDHT.h>
#include "DHT.h"
#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
String messageStatic = "Temp. & Humidity";
LiquidCrystal_I2C lcd(0x20, lcdColumns, lcdRows);  
void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

WiFiMulti wifiMulti;
char* WifiSSID="Your-SSID";
char* WifiPassword="Your-Key";
//1.replace https with http 
//2.replace youreventname with your  event name
//3.replace yourkey at the end of url with your key
String IFTTTUrl="http://maker.ifttt.com/trigger/{event name}/with/key/{iFTTT Key}";
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // initialize DHT11 sensor
  dht.begin();
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
    Serial.begin(115200);
    Serial.println();
    wifiMulti.addAP(WifiSSID, WifiPassword);  
    for(uint8_t xt = 4; xt > 0; xt--) {
        Serial.printf("[SETUP] WAIT %d...\n", xt);
        Serial.flush();
        delay(1000);
    }
}



void loop() {
    lcd.setCursor(0, 0);
    lcd.print(messageStatic);
    delay(2000);
    // wait for WiFi connection
    if((wifiMulti.run() == WL_CONNECTED)) {
        //=======Reading dht11 data==============
        Serial.println("reading DHT11...");
        //byte temperature = 0;
        //byte humidity = 0;
        //int err = SimpleDHTErrSuccess; 
        //reading data
          float h = dht.readHumidity();
          float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
        Serial.print("Reading OK: ");      
        //=======dht11 data read==========
        //regenerate url string with temp and humd
        //LCD
        //Serial.print(F("Humidity: "));
        //Serial.print(h);
        //Serial.print(F("%  Temperature: "));
        //Serial.print(t);
        char nmsg[20];
        sprintf(nmsg,"%5.2f , %3.0f%s",t,h,"\%");
        Serial.println(nmsg);
        scrollText(1, nmsg, 250,lcdColumns);

        //IFTTT
        String url=IFTTTUrl+"?value1="+String(t)+"&value2="+String(h);        

        //Start to send data to IFTTT
        HTTPClient http;
        Serial.print("[HTTP] begin...\n");
        http.begin(url); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();
        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);
            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    }
    delay(30000);//send data every 20 seconds
}
