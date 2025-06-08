import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

GPIO_TRIGGER1 = 17
GPIO_ECHO1 = 27
GPIO_TRIGGER2 = 10
GPIO_ECHO2 = 9
GPIO_TRIGGER3 = 5
GPIO_ECHO3 = 6
 
GPIO.setup(GPIO_TRIGGER1, GPIO.OUT)
GPIO.setup(GPIO_ECHO1, GPIO.IN)
GPIO.setup(GPIO_TRIGGER2, GPIO.OUT)
GPIO.setup(GPIO_ECHO2, GPIO.IN)
GPIO.setup(GPIO_TRIGGER3, GPIO.OUT)
GPIO.setup(GPIO_ECHO3, GPIO.IN)
 
def distanceDepan():
    GPIO.output(GPIO_TRIGGER1, True)
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER1, False)
    GPIO.setwarnings(False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    while GPIO.input(GPIO_ECHO1) == 0:
        StartTime = time.time()
 
    while GPIO.input(GPIO_ECHO1) == 1:
        StopTime = time.time()
 
    TimeElapsed = StopTime - StartTime
    distancedepan = (TimeElapsed * 34300) / 2
    depan = (1E-06*distancedepan*distancedepan) + (1.0055*distancedepan) + 0.0012

    return depan

def distanceKanan():
    GPIO.output(GPIO_TRIGGER2, True)
 
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER2, False)
    GPIO.setwarnings(False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    while GPIO.input(GPIO_ECHO2) == 0:
        StartTime = time.time()
 
    while GPIO.input(GPIO_ECHO2) == 1:
        StopTime = time.time()

    TimeElapsed = StopTime - StartTime
    distancekanan = (TimeElapsed * 34300) / 2
    kanan = (1E-06*distancekanan*distancekanan) + (1.0055*distancekanan) + 0.0012
 
    return kanan

def distanceKiri():
    GPIO.output(GPIO_TRIGGER3, True)

    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER3, False)
    GPIO.setwarnings(False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    while GPIO.input(GPIO_ECHO3) == 0:
        StartTime = time.time()
 
    while GPIO.input(GPIO_ECHO3) == 1:
        StopTime = time.time()
 
    TimeElapsed = StopTime - StartTime
    distancekiri = (TimeElapsed * 34300) / 2
    kiri = (1E-06*distancekiri*distancekiri) + (1.0055*distancekiri) + 0.0012
 
    return kiri
 
if __name__ == '__main__':
    try:
        while True:
            distA = distanceDepan()
            print ("Jarak Sensor Depan = %.1f cm" % distA)
            time.sleep(3)
            distB = distanceKanan()
            print ("Jarak Sensor Kanan = %.1f cm" % distB)
            time.sleep(3)
            distC = distanceKiri()
            print ("Jarak Sensor Kiri = %.1f cm" % distC)
            time.sleep(3)
 
        # Reset by pressing CTRL + C
    except KeyboardInterrupt:
        print("Measurement stopped by User")
        GPIO.cleanup()