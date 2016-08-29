#ifndef CAPTEURONEWIRE_H
#define CAPTEURONEWIRE_H

#include <OneWire.h>
//#include <DallasTemperature.h>

//OneWire oneWire(ONE_WIRE_BUS);


class capteurOneWire
{ 
  public:
    capteurOneWire(int pin);
    float lireDS18B20();
    void configureDS18B20(uint8_t alarmeSeuilHaut, uint8_t alarmeSeuilBas, uint8_t resolutionTemperature);

  private:
    OneWire oneWire; 
    byte addr[8]; 
    
    boolean rechercheAdresseCapteur(uint8_t capteur);
      
//    DallasTemperature Capteur_DS18B20;
};


#endif
