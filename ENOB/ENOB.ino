double sensorReadingA = 0;
//double start1 = 0;
//double ending1 = 0;
//double start2 = 0;
//double ending2 = 0;
//double time1 = 0;
//int ledPin = 13;
//int ledState = HIGH;
double threshhold = 1.466;
double threshhold2 = 1.955;
double sensorReadingB = 0;
#define PIEZO 34
#define BITE 32
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(GPIO_NUM_12,INPUT);
  //pinMode(ledPin,OUTPUT);
  pinMode(PIEZO,INPUT);
  pinMode(BITE,OUTPUT);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Heooooo");
  int count2 = 0;
  int count = 0;
  int bite = 0;
  sensorReadingA = analogRead(PIEZO) * 5.0 / 1023.0;
  Serial.print("AnalogReading: ");
  Serial.println(sensorReadingA);
  //sensorReadingD = sensorReadingA * 3.3 / 4095;
  //Serial.println("Analog Reading: ");
  //Serial.print(" ");
  //Serial.println(sensorReadingA);
  if (sensorReadingA >= threshhold){
    //start1 = micros();
    
    //ledState = !ledState;
    //digitalWrite(ledPin,ledState);
    while (count <= 30){
      sensorReadingB = analogRead(PIEZO)* 5.0 / 1023.0;
      Serial.print("Sensor: ");
      Serial.println(sensorReadingB);
      if (sensorReadingB >= threshhold2){
             bite++;
             count++;
      }
      else {
             count++;     
      }
      delay(100);
    }
    
    //ending1 = micros();
  }
  else {
    //ledState = LOW;
    //digitalWrite(ledPin,ledState);
  }
  Serial.print("Threshhold: ");
  Serial.println(bite);
  
  if (bite >= 8){
    //start2 = micros();
    Serial.println("B-I-T-E!!!!");
    //ending2 = micros(); 
    //Serial.print("Execution time:");
    //Serial.println(ending1+ending2-start1-start2);
    //time1 = (ending1+ending2-start1-start2) / 1000000.0;
    //Serial.print(time1);
    //Serial.println("seconds");
    while (count2 <=300){
      //digitalWrite(ledPin,ledState);
      digitalWrite(BITE,HIGH);
      count2++;
      delay(20);
    }
    
  }
  else if (bite >= 1 and bite < 8){
    Serial.println("Noise...");
  }
  //digitalWrite(ledPin,LOW);
  digitalWrite(BITE,LOW);
  //Serial.print("/t");
  //digitalWrite(GPIO_NUM_14,HIGH);
  //Serial.println(GPIO_NUM_14);
  delay(100);
}
