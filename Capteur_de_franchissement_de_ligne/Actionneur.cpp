/*********************************************************************
 * @file  Actionneur.cpp
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Classe abstraite des actionneurs
 *********************************************************************/
#include "Actionneur.h"

Actionneur::Actionneur(const String& nom, uint8_t broche, unsigned long duree)
  : Peripherique(nom, broche), duree(duree), actif(false), debut(0)
{
}

void Actionneur::activer(void)
{
  allumer();
  actif = true;
  debut = millis();
}

void Actionneur::desactiver(void)
{
  eteindre();
  actif = false;
}

void Actionneur::mettreAJour(void)
{
  if (actif && millis() - debut >= duree)
    desactiver();
}

bool Actionneur::estActif(void) const
{
  return actif;
}
