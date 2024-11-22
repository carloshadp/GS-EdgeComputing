<h1>Projeto: Monitoramento de Painéis Solares com Wi-Fi e MQTT</h1>
<p>Este projeto implementa um sistema de monitoramento para painéis solares, utilizando sensores de poeira, temperatura e umidade, conectados a um servidor MQTT para envio de dados. A interface com o usuário é realizada através de um display LCD, que exibe as informações coletadas.</p>
<h3>Descrição do Projeto 🎯</h3>
<p>O objetivo do sistema é monitorar:<br/>

Temperatura e umidade do ambiente utilizando um sensor DHT11.<br/>
Níveis de poeira acumulados sobre os painéis solares utilizando um sensor analógico.<br/>
Os dados coletados são enviados a um broker MQTT (servidor) e exibidos em tempo real em um display LCD.</p>

<h3>Recursos Utilizados 🛠</h3>
<h4>Hardware</h4>
<p>-Microcontrolador: ESP32<br/>
-Sensor de poeira (analógico)<br/>
-Sensor de temperatura e umidade: DHT11<br/>
-Display LCD com interface I2C</p>
<h4>Software</h4>
<p>-Wokwi<br/>
-Broker MQTT: test.mosquitto.org<br/>
</p>
<h3>Bibliotecas e Dependências ⚠</h3>
<p>-WiFi.h<br/>
-PubSubClient.h<br/>
-DHT.h<br/>
-LiquidCrystal_I2C.h
</p>
<h3>Instruções de Uso</h3>
<h4>Configuração do Sistema</h4>
<p>SSID da Rede Wi-Fi: Altere o valor da  ssid para o nome da sua conexão Wi-Fi.<br/>
Senha da Rede Wi-Fi: Altere o valor password com a senha da sua rede.<br/>
Servidor MQTT: Substitua o valor da constante mqtt_server com o endereço do seu servidor MQTT.</p>
<h2>INTEGRANTES</h2>
<h3>Carlos Henrique Alves RM: 558003</h3>
<h3>Maurício Alves de Souza RM: 556214</h3>
<h3>Hodrigo Hiroshi Watanabe RM: 557374</h3>
<h3>Projeto no Wokwi<h3/>
<a href="https://wokwi.com/projects/415271163058589697">Link do Wokwi</a>
