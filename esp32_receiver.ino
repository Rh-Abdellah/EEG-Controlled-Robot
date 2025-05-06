#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* topic = "braincar/control";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);  // Example pin

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT");
      client.subscribe(topic);
    } else {
      delay(1000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String command;
  for (int i = 0; i < length; i++) {
    command += (char)payload[i];
  }

  Serial.println("Command: " + command);

  if (command == "left") {
    // Add motor control logic here
    Serial.println("Turning LEFT");
  } else if (command == "right") {
    Serial.println("Turning RIGHT");
  } else if (command == "stop") {
    Serial.println("Stopping");
  }
}

void loop() {
  client.loop();
}
