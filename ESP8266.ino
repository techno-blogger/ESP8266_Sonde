
#include "ESP8266WiFi.h"
#include "logger.h"
#include "wifi.h"

logger mlog;

void setup() {

  mlog.ecrireLog("ESP8266.ino","setup","Debut du setup");

  wifi monWifi;
  monWifi.listeAllWifi();




  
  //Configuration du WIFI en mode station (emeteur)
  WiFi.mode(WIFI_STA);
  //Déconnection si nous étions en mode AP (récepteur)
  WiFi.disconnect();
  delay(100);

  mlog.ecrireLog("Fin du setup");
}

void loop() {
    mlog.ecrireLog("ESP8266.ino","loop","Debut de la fonction loop");

  // WiFi.scanNetworks retourne le nombre de reseau detecte
  int nbWifi = WiFi.scanNetworks();
    mlog.ecrireLog("scan du wifi effectué");
  if (nbWifi == 0)
    mlog.ecrireLog("Aucun réseau wifi détecté");
  else
  {
    mlog.ecrireLog(nbWifi + "réseau(x) détecté(s)");
    for (int i = 0; i < nbWifi; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);

}
