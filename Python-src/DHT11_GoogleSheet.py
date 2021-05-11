from machine import Pin
from dht import DHT11 
import network
import urequests

import esp
esp.osdebug(None)

import gc
gc.collect()

ssid = 'SSID'
password = 'Password'

api_key = 'API_key'

station = network.WLAN(network.STA_IF)
station.active(True)
station.connect(ssid, password)

while station.isconnected() == False:
  pass

print('Connection successful')
print(station.ifconfig())

# ESP32 - Pin assignement
#sensor = DHT11(Pin(4))
# ESP8266 - Pin assignement
sensor = DHT11(Pin(0))


  
 
try:
  sensor.measure()
  temp = sensor.temperature()
  humidity = sensor.humidity()
  print('Temperature: %2.2f C' %temp)
  print('Humidity: %2.2f %%' %humidity)


  sensor_readings = {'value1':temp, 'value2':humidity}
  print(sensor_readings)

  request_headers = {'Content-Type': 'application/json'}

  request = urequests.post(
    'http://maker.ifttt.com/trigger/EventName/with/key/' + api_key,
    json=sensor_readings,
    headers=request_headers)
  print(request.text)
  request.close()

except OSError as e:
  print('Failed to read/publish sensor readings.')







