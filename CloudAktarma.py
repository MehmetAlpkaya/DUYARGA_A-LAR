import serial
import time
import csv
import urllib

import requests
import urllib.request
ser = serial.Serial(port='COM9', baudrate=9600, timeout=1000)
ser.flushInput()
i=0
while i<20:
    ser_bytes = ser.readline()
    
    decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
    sicaklik=ser_bytes.decode()
    i=i+1
   
    msg=sicaklik
    msg = msg.replace(' ', "%20")
    msg = msg.replace(' ', "%0A")
  
    print(msg)
    b=urllib.request.urlopen('https://api.thingspeak.com/update?api_key=3TKZTWO49LZSWODB&field1='+msg)
    print("\nSicaklik yuklendi ")

   
    with open("test_data.csv","a") as f:
         writer = csv.writer(f,delimiter=",")
         writer.writerow([time.time(),decoded_bytes])
