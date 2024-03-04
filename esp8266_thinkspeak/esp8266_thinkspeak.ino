#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

int trigpin = D1;
int echopin = D2;
int traveltime;
int distance;

const char *ssid = "Redmi 9 Prime";
const char *password = "00000000";




unsigned long myChannelNumber = 2414006;
const char * myWriteAPIKey = "5M3FT7W7NTF4K2M5";

WiFiClient  client;


void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

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
  // put your setup code here, to run once:

}

void loop() {

  digitalWrite(trigpin,LOW);
  delayMicroseconds(1);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(1);
  traveltime = pulseIn(echopin,HIGH);
  delayMicroseconds(10);

  distance = traveltime*(0.0367/2);

  ThingSpeak.setField(1, distance);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);



  Serial.print("distance is : ");
  Serial.print(distance);
  Serial.println(" cm");

  
}
    
  // iterate over the notes of the melody:

  
