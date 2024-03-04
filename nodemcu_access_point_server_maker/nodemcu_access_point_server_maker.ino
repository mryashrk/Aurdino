#include <ESP8266WiFi.h>



void setup() {
  Serial.begin(9600);

  WiFi.softAP("nodemcu","00000000");
  Serial.print("wifi IP is : ");
  Serial.println(WiFi.softAPIP());


}

void loop() {
  Serial.print("number of devices connected : ");
  Serial.println(WiFi.softAPgetStationNum());
  delay(5000);

}
