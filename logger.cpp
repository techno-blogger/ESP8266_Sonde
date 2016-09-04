#include "logger.h"

logger::logger(){
   //Configuration de la vitesse de transfert de la liaison série.
  Serial.begin(115200);
  ancienFichierCpp = "";
  ancienneFonction = "";
}

void logger::ecrireLogSource(String fichierCpp){
  if ( fichierCpp != ancienFichierCpp ){
    nouveauFichier( fichierCpp);  
  }

  ancienFichierCpp = fichierCpp;
}

void logger::ecrireLog(String fichierCpp, String fonction,String texte) {
  if ( fichierCpp == ancienFichierCpp ){
    if ( fonction != ancienneFonction ){
      nouvelleFonction( fonction ); 
    }
  }else{
    nouveauFichier( fichierCpp); 
    nouvelleFonction( fonction );
  }

  nouveauLog(texte);
  
  ancienFichierCpp = fichierCpp;
  ancienneFonction = fonction;  
}

void logger::ecrireLog(String fonction,String texte) {
  if ( fonction != ancienneFonction ){
    nouvelleFonction( fonction ); 
  }

  nouveauLog(texte);

  ancienneFonction = fonction; 
}

void logger::ecrireLog(String texte){
  ecrireLog(ancienFichierCpp,ancienneFonction,texte);
}

void logger::nouveauFichier(String fichierCpp){
  Serial.println("");
  if (ancienFichierCpp != ""){
    Serial.println("==========================================");
  }
  Serial.println("==========================================");
  Serial.println("SOURCE   => " + fichierCpp);  
}

void logger::nouvelleFonction(String fonction){
  Serial.println("");
  Serial.println("--- FONCTION => " + fonction);
}

void logger::nouveauLog(String texte){
  if (texte != ""){
    Serial.println("             => " + texte);   
  } 
}

