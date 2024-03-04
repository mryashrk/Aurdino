// https://www.tinkercad.com/things/bzhsmSADe8b-copy-of-sizzling-robo-jofo/editel?tenant=circuits
//after lot of afferts i had made this lcd working


#include <LiquidCrystal.h>

int rs = 4;
int en = 5;
int DR4 = 6;
int DR5 = 7;
int DR6 = 8;
int DR7 = 9;

LiquidCrystal lcd(rs,en,DR4,DR5,DR6,DR7);





void setup() {
  lcd.begin(16,2);

  // put your setup code here, to run once:

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("hello world");
  // put your main code here, to run repeatedly:

}
