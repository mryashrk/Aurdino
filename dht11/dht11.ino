#include <DHT11.h>
#define DType DHT11;

int dtpin = 4;

DHT11 dht(dtpin);



void setup() {
  
  Serial.begin(9600);


  

}

void loop() {
  float tc = dht.readTemperature();
  float tf = dht.readTemperature(true);
  float humi = dht.readHumidity();

  Serial.print("Temperature is : ");
  Serial.print(tc);
  Serial.print(" ,  ");
  Serial.print("Temperature is : ");
  Serial.print(tf);
  Serial.print(" ,  ");
  Serial.print("humidity is :");
  Serial.println(humi);
  delay(1000);

}
