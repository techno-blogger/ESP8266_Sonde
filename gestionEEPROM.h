#ifndef GESTIONEEPROM_H
#define GESTIONEEPROM_H

#include "Arduino.h"
#include "logger.h"
#include <EEPROM.h>

#define TAILLE_MEMOIRE 512

typedef struct 
{
  String ssid;
  String password;
  String ipMQTT;
  int delaisRafraichissement;
  char* ssid2;  
} StructureEEPROM;

class gestionEEPROM
{ 
    
  public:
    gestionEEPROM();
    // vider le contenu de l'EEPROM
    void viderEEPROM();

    
    void ecrireSSID(String ssid);
    void ecrireSSID2(char* ssid2);
    void ecrirePassword(String password);
    void ecrireIpMQTT(String IpMQTT);
    void ecrireDelaisRafraichissement (int delais);

    String lireSSID();
    char* lireSSID2();
    String lirePassword();
    String lireIpMQTT();
    int lireDelaisRafraichissement ();


   private:
    logger mlog;
    StructureEEPROM contenuEEPROM; 
    void lireEEPROM();
    void ecrireEEPROM();


 
};

#endif

