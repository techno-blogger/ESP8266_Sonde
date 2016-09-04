#include "gestionEEPROM.h"

gestionEEPROM::gestionEEPROM(){
  mlog.ecrireLogSource("gestionEEPROM.cpp");

  mlog.ecrireLog("constructeur","définir la taille de la mémoire EEPROM");
  // quantité de mémoire EEPROM que l’on souhaite utiliser

  mlog.ecrireLog("memoire " + String(TAILLE_MEMOIRE));
//  EEPROM.begin(TAILLE_MEMOIRE);
  
//  lireEEPROM();
};

void gestionEEPROM::viderEEPROM(){
  mlog.ecrireLog("viderEEPROM","vider l'ensemble de la mémoire");
  EEPROM.begin(TAILLE_MEMOIRE);
  for (int i = 0; i < TAILLE_MEMOIRE; i++){
    EEPROM.write(i, 0);  
  }   
  mlog.ecrireLog("Fin du reset mémoire"); 
  EEPROM.end();
};

void gestionEEPROM::lireEEPROM(){
  mlog.ecrireLog("lireEEPROM","lecture de la mémoire");
  EEPROM.begin(TAILLE_MEMOIRE);
  EEPROM.get( 0, contenuEEPROM );

  delay(1000);

  mlog.ecrireLog("EEPROM SSID " + String(contenuEEPROM.ssid));
  mlog.ecrireLog("=====");
  mlog.ecrireLog("EEPROM Password " + String(contenuEEPROM.password));
  mlog.ecrireLog("=====");
  mlog.ecrireLog("EEPROM IPMQTT " + String(contenuEEPROM.ipMQTT));
  mlog.ecrireLog("=====");
  mlog.ecrireLog("EEPROM Delais " + String(contenuEEPROM.delaisRafraichissement));
  EEPROM.end();
};

void gestionEEPROM::ecrireEEPROM(){
  mlog.ecrireLog("ecrireEEPROM","ecrire dans la mémoire");
  EEPROM.begin(TAILLE_MEMOIRE);
  EEPROM.put( 0, contenuEEPROM );
  EEPROM.commit();
  EEPROM.end();
};

void gestionEEPROM::ecrireSSID(String ssid){
  mlog.ecrireLog("ecrireSSID","ecriture du SSID dans la mémoire");
  if(contenuEEPROM.ssid != ssid){
    contenuEEPROM.ssid = ssid;
    
    ecrireEEPROM();      
  }
};

String gestionEEPROM::lireSSID(){
  mlog.ecrireLog("lireSSID","lecture du SSID en mémoire");
  return contenuEEPROM.ssid ;   
};

void gestionEEPROM::ecrirePassword(String password){
  mlog.ecrireLog("ecrirePassword","ecriture du Password dans la mémoire");
  if(contenuEEPROM.password != password){
    contenuEEPROM.password = password;
    
    ecrireEEPROM();      
  }
};

String gestionEEPROM::lirePassword(){
  mlog.ecrireLog("lirePassword","lecture du Passsword en mémoire");
  return contenuEEPROM.password ;   
};

void gestionEEPROM::ecrireIpMQTT(String IpMQTT){
  mlog.ecrireLog("ecrireIpMQTT","ecriture de l'IP MQTT dans la mémoire");
  if(contenuEEPROM.ipMQTT != IpMQTT){
    contenuEEPROM.ipMQTT = IpMQTT;
    
    ecrireEEPROM();      
  }
};

String gestionEEPROM::lireIpMQTT(){
  mlog.ecrireLog("lireIpMQTT","lecture de l'IP mQTT en mémoire");
  return contenuEEPROM.ipMQTT ;   
};

void gestionEEPROM::ecrireDelaisRafraichissement(int delais){
  mlog.ecrireLog("ecrireDelaisRafraichissement","ecriture du délais de rafraichissement dans la mémoire");
  if(contenuEEPROM.delaisRafraichissement != delais){
    contenuEEPROM.delaisRafraichissement = delais;
    
    ecrireEEPROM();      
  }
};

int gestionEEPROM::lireDelaisRafraichissement(){
  mlog.ecrireLog("lireDelaisRafraichissement","lecture du délais de rafraichissement en mémoire");
  return contenuEEPROM.delaisRafraichissement;   
};
