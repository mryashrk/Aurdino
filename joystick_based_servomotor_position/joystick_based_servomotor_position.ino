// it ia a potentiometer based joystic program made by me
// by moving the joystice we can change the position of servo motors
// the working of this project can also visualise on my thinkercad acc. 
// https://www.tinkercad.com/things/2UBrZhmEY0d-stunning-jaagub-jarv/editel?tenant=circuits

#include <Servo.h>

int yaxis = A0;
int xaxis = A1;
int Xservo = 6;
int Yservo = 5;
int val_x;
int val_y;
int angle_x;
int angle_y;
Servo servo1;
Servo servo2;
void setup() {
  Serial.begin(9600);
  pinMode(Xservo,OUTPUT);
  pinMode(Yservo,OUTPUT)
  servo1.attach(Xservo);
  servo2.attach(Yservo);

}

void loop() {
  val_x = analogRead(xaxis);
  val_y = analogRead(yaxis);
  Serial.print("val of x is : ");
  Serial.print(val_x);
  Serial.print(" val of y is : ");
  Serial.print(val_y);

  angle_x = 0.17595*val_x;
  angle_y = 0.17595*val_y;
  Serial.print(" val of angle x is : ");
  Serial.print(angle_x);
  Serial.print(" val of angle y is : ");
  Serial.println(angle_y);

  servo1.write(angle_x);
  servo2.write(angle_y);


}
