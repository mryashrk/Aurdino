#include<DHT11.h>
#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>

DHT11 dht(D1);

String host = "api.thingspeak.com";
int httpPort = 80;
String url1 = "/update?api_key=9JE68I0B2AVRZMS5&field1=";
String url2 = "/update?api_key=9JE68I0B2AVRZMS5&field2=";


HTTPClient http;
WiFiClient client;






void setup() {
  Serial.begin(9600);

  WiFi.begin("Redmi 9 Prime","00000000");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(10);
    Serial.print("..");
  }
  Serial.println("connected to ");
  Serial.print(WiFi.localIP());




}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();


  Serial.print("temperature in celcius is " + (String) temp);
  Serial.println(", humidity is " + (String) humi);

  String link1 = url1 + (String) temp;
  http.begin(client,host,httpPort,link1);
  int httpCode = http.GET();



  String link2 = url2 + (String) humi;
  http.begin(client,host,httpPort,link2);
  httpCode = http.GET();
  delay(200);



}
