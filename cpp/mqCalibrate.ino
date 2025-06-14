#define MQ4_PIN A0
#define RL 10.0
float R0 = 10.0;

void setup() {
  Serial.begin(9600);
  Serial.println("Kalibrasi Sensor MQ-4...");
  R0 = calibrateSensor();
  Serial.print("Nilai R0 (kalibrasi): ");
  Serial.println(R0);
}

void loop() {
  float ppm = readMQ4();
  Serial.print("Kadar Gas Metana: ");
  Serial.print(ppm);
  Serial.println(" ppm");
  delay(2000);
}

float readMQ4() {
  int adcValue = analogRead(MQ4_PIN);
  float voltage = adcValue * (5.0 / 1023.0);
  float Rs = (5.0 - voltage) / voltage * RL;

  float ratio = Rs / R0;
  float ppm_log = (log10(ratio) - 1.46) / -0.38;
  float ppm = pow(10, ppm_log);
  return ppm;
}

float calibrateSensor() {
  float Rs_avg = 0;
  for (int i = 0; i < 50; i++) {
    int adcValue = analogRead(MQ4_PIN);
    float voltage = adcValue * (5.0 / 1023.0);
    float Rs = (5.0 - voltage) / voltage * RL;
    Rs_avg += Rs;
    delay(100);
  }
  Rs_avg = Rs_avg / 50.0;

  float R0 = Rs_avg / 4.4;
  return R0;
}