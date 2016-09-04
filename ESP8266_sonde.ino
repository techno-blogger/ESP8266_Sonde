
#include "ESP8266WiFi.h"
#include "logger.h"
#include "wifi.h"
#include "gestionEEPROM.h"

logger mlog;

void setup() {

  mlog.ecrireLog("ESP8266.ino","setup","Debut du setup");

  //Configuration du WIFI en mode station (emetteur)
  //  WIFI_STA     mode station
  //  WIFI_AP_STA  mode station et point d'acces
  //  WIFI_AP      mode point d'acces
  WiFi.mode(WIFI_STA);
  
  //Déconnection si nous étions en mode AP (récepteur)
  WiFi.disconnect();
  delay(100);

  mlog.ecrireLog("Fin du setup");
}

void loop() {
  delay(5000);
  mlog.ecrireLog("ESP8266.ino","loop","Debut de la fonction loop");

  wifi monWifi;
  monWifi.listeAllWifi();

/*  gestionEEPROM EEPROMesp8266;

  delay(1000);
  
//  EEPROMesp8266.viderEEPROM();
//  delay(1000);
  
  EEPROMesp8266.ecrireSSID("test-SSID");
  EEPROMesp8266.ecrirePassword("test-Password");
  EEPROMesp8266.ecrireIpMQTT("test-IPMQTT");
  EEPROMesp8266.ecrireDelaisRafraichissement(5);

  mlog.ecrireLog("EEPROM SSID " + String(EEPROMesp8266.lireSSID()));
  mlog.ecrireLog("EEPROM Password " + String(EEPROMesp8266.lirePassword()));
  mlog.ecrireLog("EEPROM IPMQTT " + String(EEPROMesp8266.lireIpMQTT()));
  mlog.ecrireLog("EEPROM Delais " + String(EEPROMesp8266.lireDelaisRafraichissement()));

  mlog.ecrireLog("=========");
  delay(5000);
  
  EEPROMesp8266.ecrirePassword("------");

  mlog.ecrireLog("EEPROM SSID " + String(EEPROMesp8266.lireSSID()));
  mlog.ecrireLog("EEPROM Password " + String(EEPROMesp8266.lirePassword()));
  mlog.ecrireLog("EEPROM IPMQTT " + String(EEPROMesp8266.lireIpMQTT()));
  mlog.ecrireLog("EEPROM Delais " + String(EEPROMesp8266.lireDelaisRafraichissement()));
*/
/*  // WiFi.scanNetworks retourne le nombre de reseau detecte
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
*/
  // Wait a bit before scanning again
  delay(5000);

}
