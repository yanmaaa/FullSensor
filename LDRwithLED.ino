#define ldr 8
#define led 2

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int nyala = digitalRead(ldr);
  Serial.println(nyala);
  delay(1000);
  if (nyala == LOW) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  delay(1000);
}