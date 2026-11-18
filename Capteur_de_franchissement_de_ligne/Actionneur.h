/*********************************************************************
 * @file  Actionneur.h
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Classe abstraite des actionneurs
 *********************************************************************/
#ifndef ACTIONNEUR_H_
#define ACTIONNEUR_H_

#include "Peripherique.h"

/**
  * @class Actionneur
  * @brief Peripherique active pendant une duree donnee (ms)
*/
class Actionneur : public Peripherique
{
  public :
    Actionneur(const String& nom, uint8_t broche, unsigned long duree);
    void activer(void);
    void desactiver(void);
    void mettreAJour(void);
    bool estActif(void) const;

  protected :
    virtual void allumer(void) = 0;
    virtual void eteindre(void) = 0;

  private :
    unsigned long duree;
    bool actif;
    unsigned long debut;
};

#endif
