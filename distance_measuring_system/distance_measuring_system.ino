#include <LiquidCrystal.h>

// lcd pin setup
int rs = 2;
int en = 3;
int dr4 = 4;
int dr5 = 5;
int dr6 = 6;
int dr7 = 7;
LiquidCrystal lcd(rs,en,dr4,dr5,dr6,dr7);


// ultrasonic sensor pin setup
int trigpin = 9;
int echopin = 8;
int traveltime;
float distance;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  
}

void loop() {
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(1);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin,LOW);
  
  traveltime = pulseIn(echopin,HIGH);
  delayMicroseconds(10);
  
  distance = traveltime*(0.0347/2);

  Serial.println(distance);


// print in lcd 
  lcd.setCursor(0,0);
  lcd.print("Distance is ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  

}