#define mq 7
#define LED 6

void setup() {
  Serial.begin(9600);
  pinMode(mq, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  int gas = digitalRead(mq);

  if(gas == LOW){
    Serial.println("Gas Terdeteksi");
    digitalWrite(LED, HIGH);
  } else{
    Serial.println("Udara Bersih");
    digitalWrite(LED, LOW);
  }
  delay(1000);
}