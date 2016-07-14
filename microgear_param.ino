/*  NETPIE ESP8266 basic sample                            */
/*  More information visit : https://netpie.io             */

/**
 * Plugin Name:     Netpie MicroGear Parameter
 * Description:     MicroGear Parameter to Adjustable
 * Author:          lamloei
 * Author URI:      http://www.lamloei.com
 * Modified Date:   2016071401
 * Version:         V01
 */
#include <ESP8266WiFi.h>
#include <MicroGear.h>

char ssid[20];
char password[20];
char APPID [20];
char KEY[20];
char SECRET[40];
char ALIAS[20];

WiFiClient client;
MicroGear microgear(client);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");

  strcpy(ssid,"<WIFI SSID>");
  strcpy(password,"<WIFI PASSWORD>");
  strcpy(APPID,"<APPID>");
  strcpy(KEY,"<KEY>");
  strcpy(SECRET,"<SECRET>");
  strcpy(ALIAS,"<ALIAS>");

  WiFi.mode(WIFI_STA);
  if (WiFi.begin(ssid, password)) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  microgear.init(KEY,SECRET,ALIAS);
  microgear.connect(APPID);
}

void loop() {
  if (microgear.connected()) {
    microgear.loop();
  }
  else {
    Serial.println("connection lost, reconnect...");
    microgear.connect(APPID);
  }
}
