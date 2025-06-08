#include <LiquidCrystal_I2C.h>

#define ECHO_PIN 2
#define TRIG_PIN 3
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(13, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  float y = (1E-06*distance*distance) + (1.0055*distance) + 0.0012;

  lcd.setCursor(2, 0); //2 itu adalah jumlah kolom 0 adalah barisnya
  lcd.print("Jarak: ");
  lcd.print(y);
  if (y < 200){
    lcd.setCursor(3, 1);
    lcd.print("Hati-hati!");
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    tone(12, 1000, 100);
  }
  else {
    lcd.setCursor(6, 1);
    lcd.print("Aman");
  }
  delay(100);
}