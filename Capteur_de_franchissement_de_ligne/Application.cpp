/*********************************************************************
 * @file  Apllication.cpp
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Fichier source de l'application Capteur de franchissement de ligne
 *********************************************************************/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Application.h"


const char* SSID = "T2S_Mobile";
const char* PASSWORD = "Bareauthet0n";


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
  pinMode(D5, INPUT);
  Serial.begin(115200);

  // Config Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID,PASSWORD);
  Serial.print("Connexion");

  // Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnecté ! IP : ");
  Serial.println(WiFi.localIP());

}


void Application::run(void)
{

  // Bouton poussoir qui pilote la LED interne
  if(digitalRead(D5)==LOW)
    digitalWrite(LED_BUILTIN, LOW);
  else
    digitalWrite(LED_BUILTIN, HIGH);

}
