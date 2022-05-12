#include <SimpleDHT.h>                   
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "NOME_DA_MINHA_REDE"
#define WLAN_PASS       "SENHA_DO_MEU_WIFI"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "gserafim27"
#define AIO_KEY         "aio_cLCp09VzRxWh6RKB1YqMaXIZ8dWO" 
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish Temperatura = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Temperatura");
Adafruit_MQTT_Publish Umidade = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Umidade");

int pinDHT11 = 0;
SimpleDHT11 dht11(pinDHT11);
byte hum = 0;  
byte temp = 0; 
void setup() {
  Serial.begin(115200);
  Serial.println(F("Adafruit IO Exemplo"));
  
  Serial.println(); Serial.println();
  delay(10);
  Serial.print(F("Conectando em "));
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi conectado"));
  Serial.println(F("Endereço de IP: "));
  Serial.println(WiFi.localIP());

  connect();

}

void connect() {
  Serial.print(F("Conectando em Adafruit IO... "));
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Problema de protocolo")); break;
      case 2: Serial.println(F("ID rejeitado")); break;
      case 3: Serial.println(F("Servidor indisponivel")); break;
      case 4: Serial.println(F("Usuario ou senha incorretos")); break;
      case 5: Serial.println(F("Nao autenticado")); break;
      case 6: Serial.println(F("Falha no subscribe")); break;
      default: Serial.println(F("Falha na conexao")); break;
    }

    if(ret >= 0)
      mqtt.disconnect();

    Serial.println(F("Reconectando..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Conectado!"));
}

void loop() {

  if(! mqtt.ping(3)) {

    if(! mqtt.connected())
      connect();
  }
  dht11.read(&temp, &hum, NULL);
  Serial.print((int)temp); Serial.print("ºC, "); 
  Serial.print((int)hum); Serial.println("% de Umidade");
  delay(5000);
   
   if (! Temperatura.publish(temp)) {
      Serial.println(F("Falha"));
    } 
       if (! Umidade.publish(hum)) {
      Serial.println(F("Falha"));
    }
