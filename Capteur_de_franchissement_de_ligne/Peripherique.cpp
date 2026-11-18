/*********************************************************************
 * @file  Peripherique.cpp
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Classe de base des capteurs et actionneurs
 *********************************************************************/
#include "Peripherique.h"

Peripherique::Peripherique(const String& nom, uint8_t broche) : nom(nom), broche(broche)
{
}

const String& Peripherique::getNom(void) const
{
  return nom;
}

uint8_t Peripherique::getBroche(void) const
{
  return broche;
}
