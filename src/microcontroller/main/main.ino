#include <dht11.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* SSID = "<ENTER_WIFI_SSID>";
const char* password = "<ENTER_WIFI_PASSWORD>";

const char* serverHost = "ntfy.sh";

dht11 DHT11;

int builtinLed = 2;
int sensorPin = 4;  // D2

int timeout = 10;

int lastTemp;

void  setup()
{
  Serial.begin(9600);

  pinMode(builtinLed, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, password);
  Serial.println("Started!");

  while (WiFi.status() != WL_CONNECTED && timeout > 0) {
    digitalWrite(builtinLed, HIGH);
    Serial.println("Connecting....");
    timeout--;
    delay(250);
    digitalWrite(builtinLed, LOW);
    delay(150);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected to #");
    Serial.print(SSID);
    Serial.print("# IP address: ");
    Serial.println(WiFi.localIP());

    digitalWrite(builtinLed,HIGH);
    delay(200);
    digitalWrite(builtinLed, LOW);
    delay(100);
    digitalWrite(builtinLed,HIGH);
    delay(200);
    digitalWrite(builtinLed, LOW);
    delay(100);
    digitalWrite(builtinLed,HIGH);
    delay(200);
    digitalWrite(builtinLed, LOW);

  } else {
    Serial.print("Connection failed!");
  }


}

void sendTempData(int temp) {
  WiFiClient client;

  digitalWrite(builtinLed,HIGH);

  Serial.print("sending...");
  delay(100);

  if (!client.connect(serverHost, 80)) {
    digitalWrite(builtinLed, LOW);
    Serial.println("Connection to server failed!");
    return;
  }
  String url = "/<ENTER_TOPIC_NAME>";
  String payload = String(temp);

  digitalWrite(builtinLed, LOW);

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
