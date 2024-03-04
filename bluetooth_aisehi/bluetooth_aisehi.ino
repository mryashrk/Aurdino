#include<BluetoothSerial.h>
BluetoothSerial SerialBT;
int leftpin = 6;
int rightpin = 7;

int cmd;




void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP-32");


  

}

void loop() {
  if(Serial.available()){
    cmd =SerialBT.read();
    Serial.write(cmd);
  }


  if(cmd=1){
    digitalWrite(leftpin,HIGH);
    digitalWrite(rightpin,HIGH);
  }

  if(cmd=2){
    digitalWrite(leftpin,LOW);
    digitalWrite(rightpin,HIGH);
  }

  if(cmd=3){
    digitalWrite(leftpin,HIGH);
    digitalWrite(rightpin,LOW);
  }

}
