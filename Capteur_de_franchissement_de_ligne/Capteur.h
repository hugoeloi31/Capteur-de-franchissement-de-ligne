/*********************************************************************
 * @file  Capteur.h
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Classe abstraite des capteurs
 *********************************************************************/
#ifndef CAPTEUR_H_
#define CAPTEUR_H_

#include "Peripherique.h"

/**
  * @class Capteur
  * @brief Peripherique qui detecte un etat
*/
class Capteur : public Peripherique
{
  public :
    Capteur(const String& nom, uint8_t broche) : Peripherique(nom, broche) {}
    virtual void mettreAJour(void) = 0;
    virtual bool estActif(void) const = 0;
};

#endif
