#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>

HTTPClient http;
WiFiClient client;

String host = "api.thingspeak.com";
int httpPort = 80;
String url = "/update?api_key=OIA2PFSL5MEAM6ZH&field1=";




void setup() {
  Serial.begin(9600);
  WiFi.begin("Redmi 9 Prime","00000000");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("....");
    delay(50);
  }
  Serial.print("....");
  Serial.print("....");
  Serial.print("....");
  delay(2000);
  Serial.println("connected to Redmi 9 Prime ");
  Serial.print("IP address is : ");
  Serial.println(WiFi.localIP());
  

}

void loop() {
  for(int i=0;i<=100;i++)
  {
    Serial.println(i);

  
    String link = url + (String) i;
    http.begin(client,host,httpPort,link);
    int httpcode = http.GET();


  // here we give delay of 16 second because http takes 15 second to update data in cloud .
    delay(16000);
  }

}
