#define outputPin 17

// the number of the LED pin
const int ledPin = 16;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

//Timer
unsigned long startTime;
unsigned long endTime;
unsigned long runTime;

void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  Serial.begin(9600);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
  pinMode(outputPin, OUTPUT);
  //Serial.println(ESP.getFreeHeap());
}
 
void loop(){
  
  digitalWrite(outputPin, HIGH);
  startTime = millis();
  //This is for PWM demo
  ledcWrite(ledChannel, 150);
  // increase the LED brightness
  
  /*
  //This is for demo the execution time
  //Serial.println("First");
  //Serial.println(ESP.getFreeHeap());
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
  
  // decrease the LED brightness
  digitalWrite(outputPin, LOW);
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
  */
  //digitalWrite(outputPin, LOW);
  //char* str = "1232415326437546";
  //char* garbage = "123454237947604625ewdsakh saaf hriojw omiwlkasdhlgkgdSdsg";
  
  //Serial.println("Second");
  //Serial.println(ESP.getFreeHeap());
  
  //Execution Time
  /*
  endTime = millis();
  runTime = endTime - startTime;
  Serial.println(runTime);
  */
  
}
