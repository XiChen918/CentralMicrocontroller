#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
int txValue = 0;

#define SERVICE_UUID "6E40001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E40001-B5A3-F393-E0A9-E50E24DCCA9E"

class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;  
  };

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
  }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BLEDevice::init("ESP32");

  BLEServer *pServer = BLEDevice::createServer();
  pServer -> setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer -> createService(SERVICE_UUID);

  pCharacteristic = pService -> createCharacteristic(
    CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);

  pCharacteristic -> addDescriptor(new BLE2902());

  pService -> start();

  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (deviceConnected) {
    txValue = random(-10,20);

   char txString[8];
   dtostrf(txValue, 1, 2, txString);

   pCharacteristic -> setValue(txString);

   pCharacteristic -> notify();

   Serial.println("Sent value: " + String(txString));
   delay(500);
  }
}
