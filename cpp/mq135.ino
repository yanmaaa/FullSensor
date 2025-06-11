const int mq = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(mq);
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("Kadar Gas: ");
  Serial.print(sensorValue);
  Serial.print(" |Tegangan: ");
  Serial.println(voltage);
  delay(1000);
}