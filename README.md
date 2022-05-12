# Mackenzie---IoT
Repositório destinado ao projeto de IoT - Mackenzie turma 05A

Aqui veremos um semáforo autônomo, que funcionará a base de captação de luz solar, passara a energia por um controlador de carga e alimentará uma bateria. Na bateria, teremos um sensor DHT22 que, fará a leitura da temperatura e da umidade da bateria. O projeto acompanha o uso de um Arduino Uno e um NodeMCU ESP8266, que proporcionará a conexão com a internet (via Wi-Fi), e utilizará do protocolo MQTT - io.Adafruit, para envio dos dados.

O hardware utilizado em todo o projeto:
Painel fotovoltaico 10w 12v
Controlador de carga
Bateria chumbo-ácido 12v 5Ah
Lente pisca alerta cristal
Arduino Uno R3
NodeMCU ESP8266
Sensor DHT22
Leds 10mm
Capacitores cerâmicos de disco
Transistores BC548
Resistores 220 Ohm
Resistores 22k Ohm
Caixa/Quadro painel de comando
Jumper
Servo Pan-tilt

Foi utilizada na programação, a IDE do Arduino, com bibliotecas DHT e Adafruit (para conexão via protocolo MQTT).
