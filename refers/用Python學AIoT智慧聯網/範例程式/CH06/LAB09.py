from machine import Pin
import time

button_yes=Pin(12,Pin.IN,Pin.PULL_UP)   
button_no=Pin(13,Pin.IN,Pin.PULL_UP)    

while True:
    print(button_no.value(),button_yes.value())
    time.sleep(0.1)