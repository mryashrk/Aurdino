#include "BluetoothSerial.h"
int cmd;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();
    SerialBT.write(cmd);
  }
  if (SerialBT.available()) {
    cmd = SerialBT.read();
    Serial.write(cmd);
  }
  delay(20);
}
