
// blynk id and token
#define BLYNK_TEMPLATE_ID "TMPL3w38YOslc"
#define BLYNK_TEMPLATE_NAME "soil moisture"
#define BLYNK_AUTH_TOKEN "QCTS4-w5rkgWgNrJnHZhv1waDUJcaFLY"

// libraries
#include<DHT11.h>
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

// pin description
int soilpin = A0;
int pump = D3;

DHT11 dht(D2);

#define BLYNK_PRINT Serial


// wifi credentials
char ssid[] = "Redmi 9 Prime";
char pass[] = "00000000";

void dhtdata()
{
  // dht code to read val
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  Serial.print("temperature is : ");
  Serial.print(temp);
  Serial.print("   humidity is : ");
  Serial.println(humi);

  Blynk.virtualWrite(V0,temp);
  Blynk.virtualWrite(V1,humi);

}


void moisture()
{
  // soil moisture code
  int val = analogRead(soilpin);
  Serial.print("val is : ");
  Serial.print(val);
  

  int moisture = 0.16026*(1024-val);
  Serial.print("  ,  moisture is : ");
  Serial.println(moisture);
  Blynk.virtualWrite(V2,moisture);

// pump on/off condition
  if(moisture<=30){
    digitalWrite(pump,1);
    Blynk.virtualWrite(V3,1);

  }
  else
  {
    digitalWrite(pump,0);
    Blynk.virtualWrite(V3,0);

  }

}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop() {
  Blynk.run();
  dhtdata();
  moisture();

  
  

  delay(1000);





}
