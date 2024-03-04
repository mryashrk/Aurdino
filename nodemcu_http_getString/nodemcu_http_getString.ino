#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>

WiFiClient client;
HTTPClient http;

String url = "";


void setup() {
  Serial.begin(9600);
  WiFi.begin("Redmi 9 Prime","00000000");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
  }
  delay(2000);
  Serial.println("connected to :");
  Serial.print(WiFi.localIP());
  

}

void loop() {
  http.begin(client,url);
  int httpcode = http.GET();
  String message = http.getString();
  Serial.println(message);

 
  delay(5000);


  

}
