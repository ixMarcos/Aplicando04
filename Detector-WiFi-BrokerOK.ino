#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Teste-2.4G";
const char* password = "12345678";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "CensorMovimento";

const int pirPin = D0; // Pino GPIO ao qual o sensor PIR está conectado

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("Conectado ao WiFi");

  // Configura o servidor MQTT
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  int pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    Serial.println("Movimento detectado!");
    
    if (!client.connected()) {
      reconectarMQTT();
    }

    client.publish(mqttTopic, "Alerta!!! movimento detectado");
  }

  delay(500);
}

void reconectarMQTT() {
  while (!client.connected()) {
    Serial.println("Conectando ao servidor MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Conectado ao servidor MQTT");
    } else {
      Serial.print("Falha na conexão, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}


