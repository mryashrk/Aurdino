#define BLYNK_TEMPLATE_ID "TMPL3fs9ZmZUX"
#define BLYNK_TEMPLATE_NAME "OTA"
#define BLYNK_AUTH_TOKEN "X1lfG94l04DsWm30fXx5lC4BPlsxkDEW"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT11.h>

DHT11 dht(D5);


#define BLYNK_PRINT Serial



char ssid[] = "Redmi 9 Prime";
char pass[] = "00000000";

BlynkTimer timer;


void dhtdata()
{
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  Serial.print("temperature is : ");
  Serial.print(temp);
  Serial.print("   humidity is : ");
  Serial.println(humi);

  Blynk.virtualWrite(V1,temp);
  Blynk.virtualWrite(V2,humi);
 

}






void setup() {
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L,dhtdata);
}

void loop() {
  Blynk.run();
  timer.run();

}
