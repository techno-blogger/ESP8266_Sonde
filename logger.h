#ifndef LOGGER_H
#define LOGGER_H

#include "Arduino.h"

class logger
{ 
  private:
    String ancienFichierCpp;
    String ancienneFonction;
     
    void nouveauFichier(String fichierCpp);
    void nouvelleFonction(String fonction);
    void nouveauLog(String texte);
    

  public:
    logger();
    void ecrireLogSource(String fichierCpp);
    void ecrireLog(String fichierCpp, String fonction, String texte);
    void ecrireLog(String fonction, String texte);
    void ecrireLog(String texte);
};

#endif

