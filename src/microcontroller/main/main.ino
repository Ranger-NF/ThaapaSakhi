#include <dht11.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* SSID = "Useless";
const char* password = "Useless@24";

const char* serverHost = "ntfy.sh";

int sensorPin = 4;  // D2

dht11 DHT11;
int timeout = 10;

int lastTemp;

void  setup()
{
  Serial.begin(9600);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, password);
  Serial.println("Started!");

  while (WiFi.status() != WL_CONNECTED && timeout > 0) {
    Serial.println("Connecting....");
    timeout--;
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected to #");
    Serial.print(SSID);
    Serial.print("# IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.print("Connection failed!");
  }

 
}

void sendTempData(int temp) {
  WiFiClient client;

  Serial.print("sending...");

  if (!client.connect(serverHost, 80)) {
    Serial.println("Connection to server failed!");
    return;
  }
  String url = "/thaapasakhi-server";
  String payload = String(temp);

  client.print("POST " + url + " HTTP/1.1\r\n" +
               "Host: " + serverHost + "\r\n" +
               "Content-Type: application/json\r\n" +
               "Content-Length: " + payload.length() + "\r\n" +
               "Connection: close\r\n\r\n" +
               payload);

}

void loop()
{
  Serial.println();

  int chk = DHT11.read(sensorPin);

  if (chk != -1) {
    Serial.println("Sensor Disconnected");
  } else {

    float tempReading = DHT11.temperature;
    Serial.println(tempReading);

    if (lastTemp != tempReading) {
      lastTemp = tempReading;
      sendTempData(tempReading);
    }

  }


  delay(2000);

}