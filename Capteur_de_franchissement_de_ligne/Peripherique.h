/*********************************************************************
 * @file  Peripherique.h
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Classe de base des capteurs et actionneurs
 *********************************************************************/
#ifndef PERIPHERIQUE_H_
#define PERIPHERIQUE_H_

#include <Arduino.h>

/**
  * @class Peripherique
  * @brief Classe abstraite commune aux capteurs et actionneurs
*/
class Peripherique
{
  
  public :
    Peripherique(const String& nom, uint8_t broche);
    virtual ~Peripherique() {}
    virtual void init(void) = 0;
    const String& getNom(void) const;
    uint8_t getBroche(void) const;

  protected :
    String nom;
    uint8_t broche;
};

#endif
