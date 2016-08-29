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
} StructureEEPROM;

class gestionEEPROM
{ 
    
  public:
    gestionEEPROM();
    // vider le contenu de l'EEPROM
    void viderEEPROM();
    void lireEEPROM();
    void ecrireEEPROM();
    
    void ecrireSSID(String ssid);
    void ecrirePassword(String password);
    void ecrireIpMQTT(String IpMQTT);
    void ecrireDelaisRafraichissement (int delais);

    String lireSSID();
    String lirePassword();
    String lireIpMQTT();
    int lireDelaisRafraichissement ();


   private:
    StructureEEPROM contenuEEPROM; 


 
};

#endif

