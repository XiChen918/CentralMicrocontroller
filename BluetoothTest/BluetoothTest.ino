#include "BluetoothSerial.h" //Header File for Serial Bluetooth
#include <stdio.h>
#include <string.h>

BluetoothSerial ESP_BT; //Object for Bluetooth
char incoming;

void setup() {
  Serial.begin(115200); 
  ESP_BT.begin("ESP32_Fish_Tech_Inc"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {

    if (ESP_BT.available()) {
      incoming = ESP_BT.read(); //Read what we recevive  
      if (incoming) {
        Serial.print(incoming);
      }
        //ESP_BT.println("Hello 49022");
      //}
      //if (incoming == 'b') {
        //Serial.print("Not yet");
      //}
      incoming = 0;
    }
}
