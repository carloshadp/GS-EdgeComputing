#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pin_poeira 35
#define DHTPIN 5
#define DHTTYPE DHT11

int poeira = 0;
int qtd_POEIRA = 0;


LiquidCrystal_I2C lcd(0x27, 20, 4); 
DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "";
const char* password = "";
const char* mqtt_server = "";

WiFiClient WOKWI_Client;
PubSubClient client(WOKWI_Client);


void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando com ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando com MQTT ...");
    if (client.connect("WOKWI_Client")) {
      Serial.println("Conectado");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" tentando denovo em 5s");
      delay(5000);
    }
  }
}

void setup() {
  
  Serial.begin(115200);
  dht.begin();

  lcd.init();           
  lcd.backlight();      
  pinMode(pin_poeira, INPUT);

  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  poeira = analogRead(pin_poeira);
  qtd_POEIRA = map(poeira, 0, 1023, 0, 255);

 
  char msg_h[10], msg_t[10], msg_p[10];
  dtostrf(h, 6, 2, msg_h);
  dtostrf(t, 6, 2, msg_t);
  itoa(qtd_POEIRA, msg_p, 10);

  client.publish("sensor/greenascent/temperature", msg_t);
  client.publish("sensor/greenascent/humidity", msg_h);
  client.publish("sensor/greenascent/poeira", msg_p);

 
  lcd.clear();

  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print(" C");


  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(h, 1);
  lcd.print(" %");


  lcd.setCursor(0, 2);
  if (qtd_POEIRA > 200 && qtd_POEIRA <= 400) {
    lcd.print("Sujeira detectada");
  } else if (qtd_POEIRA > 400 && qtd_POEIRA <= 600) {
    lcd.print("Painel Sujo");
  } else if (qtd_POEIRA > 600) {
    lcd.print("Necessario Limpeza");
  } else {
    lcd.print("Painel Limpo");
  }

  
  lcd.setCursor(0, 3);
  lcd.print("Poeira: ");
  lcd.print(qtd_POEIRA);


  Serial.print("Temperatura: ");
  Serial.println(t);
  Serial.print("Umidade: ");
  Serial.println(h);
  Serial.print("Poeira: ");
  Serial.println(qtd_POEIRA);

  
  delay(2000);
}
