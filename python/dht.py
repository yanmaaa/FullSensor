import Adafruit_DHT
import time
from gpiozero import LED
from time import sleep

DHT_SENSOR = Adafruit_DHT.DHT11
DHT_PIN = 4
ledhijau = LED(8)
ledmerah = LED(25)

while True:
    humidity, temperature = Adafruit_DHT.read(DHT_SENSOR, DHT_PIN)
    if humidity is not None and temperature is not None:

        if temperature <= 30:
            print("Temp={0:0.1f}*C  Humidity={1:0.1f}%".format(temperature, humidity))
            print("suhu normal")
            ledhijau.on()
            ledmerah.off()
            sleep(1)

        elif temperature >= 31:
            print("Temp={0:0.1f}*C  Humidity={1:0.1f}%".format(temperature, humidity))
            print("suhu panas")
            ledhijau.off()
            ledmerah.on()
            sleep(1)

        else :
            print("Sensor tidak bekerja dengan baik !")
        time.sleep(1)