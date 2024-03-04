// libraries attached
#include<ThingSpeak.h>
#include<ESP8266WiFi.h>
#include<DHT11.h>

// pin define
int dhtpin = D1;

// object creation 
DHT11 dht(dhtpin);

// wifi creation
const char *ssid = "Redmi 9 Prime";
const char *password = "00000000";

// thingspeak channel and write key 
unsigned long myChannelNumber = 2415082;
const char *myWriteAPIKey = "9JE68I0B2AVRZMS5";

WiFiClient client;


// setup

void setup() {
  pinMode(dhtpin,OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid,password);

 // wifi connetion
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);


}

void loop() {

  //  data 
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  // data print
  Serial.print(" temperature is : ");
  Serial.print(temp);
  Serial.print("'C  ");
  Serial.print("  humidity is : ");
  Serial.println(humi);


  // sending to thingspeak
  ThingSpeak.setField(1,temp);
  ThingSpeak.setField(2,humi);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);


 

}
