
#include "ESP8266WiFi.h"
#include "logger.h"
#include "wifi.h"
#include "gestionEEPROM.h"

//IPAddress ip(192, 168, 0, 177);
logger mlog;
gestionEEPROM EEPROMesp8266;

void setup() {

  mlog.ecrireLog("ESP8266.ino", "setup", "Debut du setup");

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

/*
  void test_EEPROM() {
  gestionEEPROM EEPROMesp8266;

  delay(1000);

  //  EEPROMesp8266.viderEEPROM();
  //  delay(1000);

  EEPROMesp8266.ecrireSSID("test-SSID");
  EEPROMesp8266.ecrirePassword("test-Password");
  EEPROMesp8266.ecrireIpMQTT("test-IPMQTT");
  EEPROMesp8266.ecrireDelaisRafraichissement(5);
  EEPROMesp8266.ecrireSSID2("test-SSID2");

  mlog.ecrireLog("EEPROM SSID " + String(EEPROMesp8266.lireSSID()));
  mlog.ecrireLog("EEPROM Password " + String(EEPROMesp8266.lirePassword()));
  mlog.ecrireLog("EEPROM IPMQTT " + String(EEPROMesp8266.lireIpMQTT()));
  mlog.ecrireLog("EEPROM Delais " + String(EEPROMesp8266.lireDelaisRafraichissement()));
  mlog.ecrireLog("EEPROM SSID2 " + String(EEPROMesp8266.lireSSID2()));

  mlog.ecrireLog("=========");
  delay(5000);

  EEPROMesp8266.ecrireSSID("---- test-SSID");
  EEPROMesp8266.ecrirePassword("---- test-Password");
  EEPROMesp8266.ecrireIpMQTT("----- test-IPMQTT");
  EEPROMesp8266.ecrireDelaisRafraichissement(5);
  EEPROMesp8266.ecrireSSID2("----- test-SSID2");

  mlog.ecrireLog("EEPROM SSID " + String(EEPROMesp8266.lireSSID()));
  mlog.ecrireLog("EEPROM Password " + String(EEPROMesp8266.lirePassword()));
  mlog.ecrireLog("EEPROM IPMQTT " + String(EEPROMesp8266.lireIpMQTT()));
  mlog.ecrireLog("EEPROM Delais " + String(EEPROMesp8266.lireDelaisRafraichissement()));
  mlog.ecrireLog("EEPROM SSID2 " + String(EEPROMesp8266.lireSSID2()));

  }
*/

void loop() {
  mlog.ecrireLog("ESP8266.ino", "loop", "Debut de la fonction loop");
  delay(2000);
  //  test_EEPROM();
  /*
    const char* ssid = EEPROMesp8266.lireSSID().c_str();
    const char* password = "your-password";


    //connexion au wifi grace au SSID et au mot de passe de l'EEPROM
    mlog.ecrireLog("Connexion au WIFI");
    // ssid = EEPROMesp8266.lireSSID().c_str();


    WiFi.begin(String("vv"), String("dd"));

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      mlog.ecrireLog(".");
    }

    mlog.ecrireLog("Vous etes maintenant connecté au WIFI ayant le SSID : " + String(EEPROMesp8266.lireSSID()));
    mlog.ecrireLog("IP : " + WiFi.localIP());



    wifi monWifi;
    monWifi.listeAllWifi();

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
}



