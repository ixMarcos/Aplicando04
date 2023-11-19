# Documentação: Montagem do ESP8266 com Sensor de Movimento PIR

Este documento fornece instruções detalhadas sobre como montar o ESP8266 com um Sensor de Movimento PIR (Passive Infrared) diretamente. Este projeto visa demonstrar a integração desses dois componentes para criar um sistema que envia alertas quando o sensor de movimento é acionado.

## Componentes Necessários:

- 1 ESP8266 NodeMCU V3
- 1 Sensor de Movimento PIR HC-SR501
- 3 Cabos de Conexão (Vermelho, Amarelo, Preto)

## Procedimento de Montagem:

### 1. Conexão do Fio Vermelho:
   - Conecte o fio vermelho ao primeiro pino do Sensor de Movimento PIR.
   - Conecte o mesmo fio vermelho ao pino de 5 volts (VCC) do ESP8266.

### 2. Conexão do Fio Amarelo:
   - Conecte o fio amarelo ao pino GND do Sensor de Movimento PIR.
   - Conecte o mesmo fio amarelo ao pino GND do ESP8266.

### 3. Conexão do Fio Preto:
   - Conecte o fio preto à porta digital D0 do Sensor de Movimento PIR.

## Considerações Importantes:

- Certifique-se de verificar a polaridade correta ao conectar os fios aos pinos correspondentes.
- Realize a montagem com os componentes desligados para evitar curtos-circuitos acidentais.

## Funcionamento do Projeto:

1. O Sensor de Movimento PIR detectará movimento e enviará um sinal para o ESP8266.
2. O ESP8266, ao ser acionado pelo sensor, se conectará através do Wi-Fi a um broker MQTT.
3. Uma mensagem de alerta será enviada para um dispositivo (por exemplo, celular) por meio do broker MQTT, indicando que o sensor foi acionado.

## Teste do Projeto:

1. Coloque o sensor em uma área onde o movimento seja detectado facilmente.
2. Alimente o projeto com a energia necessária.
3. Observe a conexão bem-sucedida do ESP8266 ao broker MQTT e o recebimento de alertas quando o sensor é acionado.

Este projeto básico proporciona uma introdução à integração do ESP8266 com um Sensor de Movimento PIR para criar um sistema de alerta de movimento. Para informações mais avançadas, consulte a documentação específica de cada componente e as configurações de software necessárias para o seu caso de uso.
