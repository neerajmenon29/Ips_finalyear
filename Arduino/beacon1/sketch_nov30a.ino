
#include <ESP8266WiFi.h>

const char *ssid = "BEACON_1";
const char *password = "12345678";

#define LED D0

IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid,password) ? "Ready" : "Failed!");
  //WiFi.softAP(ssid);
  //WiFi.softAP(ssid, password, channel, hidden, max_connection)
  
  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  digitalWrite(LED, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually 
                        //the LED is on; this is because it is acive low on the ESP8266.
    delay(1000);            // wait for 1 second.
    digitalWrite(LED, LOW); // turn the LED on.
   delay(1000); // wait for 1 second

  Serial.print("[Server Connected] ");
  Serial.println(WiFi.softAPIP());

  delay(500);
}