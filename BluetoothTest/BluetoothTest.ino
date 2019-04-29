#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;
int RPMArray[3] = {0,0,0};


//int relayPin = 23;
/* 
void processReceivedValue(char command){
 
  if(command == '1'){ digitalWrite(relayPin, HIGH); }
  else if(command == '0'){ digitalWrite(relayPin, LOW);}
 
   return;
}*/
 
void setup() {
  Serial.begin(115200);  
//  int RPMArray[3];

  if(!SerialBT.begin("ESP32")){
    Serial.println("An error occurred initializing Bluetooth");
  }else{
    Serial.println("Bluetooth initialized");
  }
}
 
void loop() {
  int ind = 0;
  while (SerialBT.available()) {
    
    while (ind <= 2) {
      char command = SerialBT.read();
      RPMArray[ind] = command - '0';
      ind++;
    }

    int RPM = RPMArray[0] * pow(10,2) + RPMArray[1] * pow(10,1) + RPMArray[2] * pow(10,0);
    Serial.println(RPM);
  }
  delay(2000);
  SerialBT.print("Zai? KKP");
  delay(5000);
  SerialBT.print("NM$L");
  delay(2000);
  SerialBT.print("带带大师兄");
  delay(5000);
  
}
