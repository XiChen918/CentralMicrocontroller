#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
BluetoothSerial ESP_BT; //Object for Bluetooth
char incoming;
int incomingint;
//int LED_BUILTIN = 2;
void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32_LED_Control"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {
  /*
  if (Serial.available() > 0) {    // is a character available?
    incoming= Serial.read();       // get the character
    incomingint = atoi(incoming);
    Serial.println(incoming);
    ESP_BT.print(incoming);   
  }*/
  Serial.println("One Cycle");
  ESP_BT.println("Request RPM");
  delay(2000);
  ESP_BT.println("Wait for bite");
  delay(2000);
  ESP_BT.println("Fish bited");
  delay(2000);
  ESP_BT.println("70");
  delay(2000);
  ESP_BT.println("Start Retraction directly");
  delay(2000);
  ESP_BT.println("Overload");
  delay(2000);
}
