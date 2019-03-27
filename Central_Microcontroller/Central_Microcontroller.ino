// the number of the LED pin
#define ANALOG_PIN_0 34

#define PINOUT 16
//#define PWM_PIN 
#define USER_PIN 35

//#define PWM_PIN 5

//Detector
int analog_value = 0;
//float digital_value;
unsigned long starttime,endtime; 

//User
int user_value = 0;
float user_digital;
 
//PWM
/*
int pwm_value;
float pwm_digital;
*/
int count = 0;


void setup(){
  // configure LED PWM functionalitites
  pinMode(PINOUT, OUTPUT);
  //pinMode(PWM_PIN, INPUT);
  pinMode(USER_PIN,INPUT);
  pinMode(ANALOG_PIN_0, INPUT);
  Serial.begin(9600);
  delay(1000); 

}
 
void loop(){
  analog_value = analogRead(ANALOG_PIN_0);
  
  Serial.println("No Fish");

  float digital_value = analog_value*(5.0/1023.0);
  //Serial.println(digital_value);
  
  //Once detected fish is hooked
  
  if (digital_value > 2.0) {
    Serial.println("Hooked");
    starttime=millis();
    endtime=starttime;
    
    //After several seconds, stop retracting fishing line, set digital_value to 0
    
    while ((endtime-starttime)<50000) {
      digitalWrite(PINOUT, HIGH);      
      Serial.println("Retracting");
      //keep reading user interruption
      user_value=analogRead(USER_PIN);
      user_digital = user_value * (5.0 / 1023.0);
  
      if (user_digital >= 4.0) {
        Serial.println("User Interrupt!");
        digital_value = 0;
        digitalWrite(PINOUT, LOW);
        break;
      }
      endtime=millis();
    }
    digital_value = 0;
   }
   delay(100);
}
