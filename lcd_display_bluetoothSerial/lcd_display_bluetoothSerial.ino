#include<BluetoothSerial.h>
#include<LiquidCrystal.h>

int rs = 2;
int en = 3;
int dr4 = 4;
int dr5 = 5;
int dr6 = 6;
int dr7 = 7;

int cmd;

LiquidCrystal lcd(rs,en,dr4,dr5,dr6,dr7);
BluetoothSerial SerialBT;



void setup() {
  Serial.begin(9600);
  SerialBT.begin("esp32");
  lcd.begin(16,2);
  

}

void loop() {
  if(Serial.available()){
    cmd = SerialBT.read();
    Serial.write(cmd);
    lcd.setCursor(0,0);
    lcd.write(cmd);
  }
  delay(20);



  
  

}
