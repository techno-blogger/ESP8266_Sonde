#include "gestionEEPROM.h"

gestionEEPROM::gestionEEPROM(){
  // 512 quantité de mémoire EEPROM que l’on souhaite utiliser
  EEPROM.begin(TAILLE_MEMOIRE);
  lireEEPROM();
};

void gestionEEPROM::viderEEPROM(){
  for (int i = 0; i < TAILLE_MEMOIRE; i++){
    EEPROM.write(i, 0);  
  }    
};

void gestionEEPROM::lireEEPROM(){
  EEPROM.get( 0, contenuEEPROM );
};

void gestionEEPROM::ecrireEEPROM(){
  EEPROM.put( 0, contenuEEPROM );
};

void gestionEEPROM::ecrireSSID(String ssid){
  if(contenuEEPROM.ssid != ssid){
    contenuEEPROM.ssid = ssid;
    
    ecrireEEPROM();      
  }
};

String gestionEEPROM::lireSSID(){
  return contenuEEPROM.ssid ;   
};

void gestionEEPROM::ecrirePassword(String password){
  if(contenuEEPROM.password != password){
    contenuEEPROM.password = password;
    
    ecrireEEPROM();      
  }
};

String gestionEEPROM::lirePassword(){
  return contenuEEPROM.password ;   
};

void gestionEEPROM::ecrireIpMQTT(String IpMQTT){
  if(contenuEEPROM.ipMQTT != IpMQTT){
    contenuEEPROM.ipMQTT = IpMQTT;
    
    ecrireEEPROM();      
  }
};

String gestionEEPROM::lireIpMQTT(){
  return contenuEEPROM.ipMQTT ;   
};

void gestionEEPROM::ecrireDelaisRafraichissement(int delais){
  if(contenuEEPROM.delaisRafraichissement != delais){
    contenuEEPROM.delaisRafraichissement = delais;
    
    ecrireEEPROM();      
  }
};

int gestionEEPROM::lireDelaisRafraichissement(){
  return contenuEEPROM.delaisRafraichissement;   
};
