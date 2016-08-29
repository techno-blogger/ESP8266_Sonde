#include "capteurOneWire.h"



capteurOneWire::capteurOneWire(int pin) : 
    oneWire(pin)
{
}


boolean capteurOneWire::rechercheAdresseCapteur(uint8_t capteur){
   
  oneWire.reset_search();
  
  while(oneWire.search(addr) && addr[0] != capteur){
    if ( oneWire.crc8(addr, 7) != addr[7]) {
      Serial.println("Erreur de contrôle de redondance cyclique, erreurs de transmission");  
      return false;
    }
  }
  return true;
}

float capteurOneWire::lireDS18B20(){
  float temperature;
  byte data[9];
  
  temperature = 0;

  if (rechercheAdresseCapteur(0x28)){
      oneWire.reset();             // On reset le bus 1-Wire
      oneWire.select(addr);        // On sélectionne le DS18B20
       
      oneWire.write(0x44, 1);      // On lance une prise de mesure de température
      delay(800);             // Et on attend la fin de la mesure
       
      oneWire.reset();             // On reset le bus 1-Wire
      oneWire.select(addr);        // On sélectionne le DS18B20
      oneWire.write(0xBE);         // On envoie une demande de lecture du scratchpad
     
      for (byte i = 0; i < 9; i++) // On lit le scratchpad
        data[i] = oneWire.read();       // Et on stock les octets reçus
       
      // Calcul de la température en degré Celsius
      temperature = ((data[1] << 8) | data[0]) * 0.0625;     
  }
  return temperature;
}

void capteurOneWire::configureDS18B20(uint8_t alarmeSeuilHaut, uint8_t alarmeSeuilBas, uint8_t resolutionTemperature){
  if (rechercheAdresseCapteur(0x28)){
    oneWire.reset(); 
    oneWire.select(addr);
    oneWire.write(0x4E); 
    oneWire.write(alarmeSeuilHaut);
    oneWire.write(alarmeSeuilBas);
    oneWire.write(resolutionTemperature);  
  }
  
}
