#include <DHT.h>

#define LED_HIJAU 7
#define LED_MERAH 6
#define BUZZER 8
#define DHT_PIN 5
#define DHTTYPE 22

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(BUZZER, OUTPUT );

  digitalWrite(LED_HIJAU, LOW);
  digitalWrite(LED_MERAH, LOW);
  
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  int suhu = dht.readTemperature();
  int kel = dht.readHumidity();

  if( suhu <= 30 && kel >= 30) {
    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(LED_MERAH, LOW);
    Serial.print("Suhu Normal ");
    Serial.println("Kelembapan normal");
  } else if (suhu > 30 && kel < 30) {
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    Serial.print("Suhu Panas ");
    Serial.println("Kelembapan rendah");
    tone(BUZZER, 1000);
  } else {
    Serial.println("Parameter tidak sesuai");
  }
  delay(1500);
}
