#define BLYNK_TEMPLATE_ID           "TMPL3hwHVN6X1"
#define BLYNK_TEMPLATE_NAME         "nodemcu"
#define BLYNK_AUTH_TOKEN            "pUQ_Ge4bglqN_lzn0qq3W1bp2MDonDzj"


#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi 9 Prime";
char pass[] = "00000000";

BlynkTimer timer;


void randomdata()
{
    
  Serial.println(random(0,100));
  Blynk.virtualWrite(V0,random(0,100));

}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L,randomdata);
  
}

void loop()
{
  
  Blynk.run();
  timer.run();
  
}