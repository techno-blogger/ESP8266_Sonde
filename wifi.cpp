#include "wifi.h"


wifi::wifi(){
  mlog.ecrireLogSource("Wifi.cpp");
  mlog.ecrireLog("constructeur","Configuration du WIFI en mode station (emetteur)");
  WiFi.mode(WIFI_STA);
  mlog.ecrireLog("Déconnection si nous étions en mode AP (récepteur)");
  WiFi.disconnect();
  mlog.ecrireLog("attente de 100 ms");
  delay(100);

  nbWifiTrouve = 0;
}

int wifi::nbWifi(){

  if (nbWifiTrouve == 0){
    scanReseauWifi();  
  }
  
  mlog.ecrireLog("nbWifi",String(nbWifiTrouve) + " réseau(x) wifi trouvé(s)");
  return nbWifiTrouve;
}

WifiDetail wifi::listeUnWifi(int numWifi){
  mlog.ecrireLog("listeWifi","");
  WifiDetail reseauWifi;

  if (nbWifiTrouve == 0){
    scanReseauWifi();  
  }
  
  if (numWifi <= nbWifiTrouve ){
    reseauWifi.ssid = WiFi.SSID(numWifi);
    reseauWifi.rssi = WiFi.RSSI(numWifi);
    reseauWifi.cryptage = WiFi.encryptionType(numWifi);
  }else{
    reseauWifi.ssid = "";
    reseauWifi.rssi = "";
    reseauWifi.cryptage = "";
  }

  mlog.ecrireLog("listeWifi","SSID : " + reseauWifi.ssid + " | RSSI : " + reseauWifi.rssi + " | Cryptage : " + reseauWifi.cryptage);
//  mlog.ecrireLog("listeWifi","RSSI : " + reseauWifi.rssi);
//  mlog.ecrireLog("listeWifi","Cryptage : " + reseauWifi.cryptage);
  
  return reseauWifi;
}

void wifi::listeAllWifi(){

  if (nbWifiTrouve == 0){
    scanReseauWifi();  
  }
  
  for (int i = 0; i < nbWifiTrouve; ++i)
  {
    listeUnWifi(i);
  }  
}

void wifi::scanReseauWifi(){
  mlog.ecrireLog("scanReseauWifi","");
  
  mlog.ecrireLog("Debut du Scan du reseau WIFI");
  nbWifiTrouve = WiFi.scanNetworks();

  mlog.ecrireLog("Scan du reseau WIFI terminé");
  if (nbWifiTrouve == 0)
    mlog.ecrireLog("Pas de réseau WIFI trouvé");
  else
  {
    mlog.ecrireLog( String(nbWifiTrouve) + "  WIFI trouvés" );
  }
}

