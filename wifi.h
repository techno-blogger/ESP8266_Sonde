#ifndef WIFI_H
#define WIFI_H

#include "Arduino.h"
#include "logger.h"
#include "ESP8266WiFi.h"

typedef struct 
    {
      String ssid;
      String rssi;
      String cryptage;
    } WifiDetail;

class wifi
{ 
  private:
    logger mlog;
    int nbWifiTrouve;
    
    void scanReseauWifi();                  // scan le wifi pour lister les reseaux disponibles
      
  public:
    wifi();                                 // Configuration du wifi en mode station (récepteur)
    int nbWifi();                           // Nombre de reseau wifi trouve
    WifiDetail listeUnWifi(int numWifi);    // retourne le détail du réseau wifi identifé par son nombre
    void listeAllWifi();                    // retourne le détail des reseaux wifi
};

#endif
