#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin = 4;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
    Serial.begin(9600);
    ss.begin(GPSBaud);
}

void loop() {
    delay (1000);
    while (ss.available() > 0)
    gps.encode(ss.read());

    if (gps.location.isValid()){
    double latitude=gps.location.lat();
    Serial.print(latitude,6);
    Serial.print(F("|"));
    Serial.println(gps.location.lng(), 6);
}
    delay (100); 
}