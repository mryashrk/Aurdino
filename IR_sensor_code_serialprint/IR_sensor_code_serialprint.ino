int irpin = 9;

void setup() {
  pinMode(irpin,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  // this sensor moduke only work on digitalread not in analogread
  int data = digitalRead(irpin);
  Serial.println(data);
  delay(1000);
  // put your main code here, to run repeatedly:

}
