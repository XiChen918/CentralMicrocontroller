#define AUDIO_PIN 34

int analog;

void setup() {
  Serial.begin(9600);
  //adcAttachPin(AUDIO_PIN);
  pinMode(AUDIO_PIN,INPUT);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  //adcAttachPin(AUDIO_PIN);
  //adcStart(AUDIO_PIN);
  //analogReadResolution(10); // Default of 12 is not very linear. Recommended to use 10 or 11 depending on needed resolution.
  //analogSetAttenuation(ADC_6db); // Default is 11db which is very noisy. Recommended to use 2.5 or 6.
  analog = analogRead(AUDIO_PIN);
  Serial.println(analog);
  /*
  pinMode(AUDIO_PIN, INPUT);
  for (;;)
  {
    Serial.println(analogRead(AUDIO_PIN));
    delay(500);
  }*/
  delay(100);
}
