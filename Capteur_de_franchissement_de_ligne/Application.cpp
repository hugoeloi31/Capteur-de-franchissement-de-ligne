/*********************************************************************
 * @file  Apllication.cpp
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Fichier source de l'application Capteur de franchissement de ligne
 *********************************************************************/
#include <Arduino.h>
#include "Application.h"


Application::Application()
{
  // Code
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
}


void Application::run(void)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
