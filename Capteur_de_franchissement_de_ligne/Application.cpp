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


#define PIN_IR_TX D5
#define PIN_IR_RX D6
#define NB_SANS_SIGNAL_MAX 3
#define PIN_BUZZER D7
#define VOLUME_BUZZER 40
#define DUREE_BUZZER_MS 500


Application::Application() : emetteurIR(PIN_IR_TX), obstacle(false), nbSansSignal(0), buzzerActif(false), debutBuzzer(0)
{
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  pinMode(PIN_IR_RX, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  analogWrite(PIN_BUZZER, 0);
  emetteurIR.begin();
  emetteurIR.enableIROut(38);
  Serial.begin(115200);
  Serial.println("\nBarriere IR prete");

  // Config Wi-Fi
/*   WiFi.mode(WIFI_STA);
  WiFi.begin(SSID,PASSWORD);
  Serial.print("Connexion"); */

  // Wi-Fi connection
  /* while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnecté ! IP : ");
  Serial.println(WiFi.localIP());
*/
}


void Application::run(void)
{
  // Salve 38 kHz 
  emetteurIR.mark(600);
  bool signalRecu = (digitalRead(PIN_IR_RX) == LOW);
  emetteurIR.space(600);

  if (signalRecu)
    nbSansSignal = 0;
  else if (nbSansSignal < NB_SANS_SIGNAL_MAX)
    nbSansSignal++;

  bool faisceauCoupe = (nbSansSignal >= NB_SANS_SIGNAL_MAX);
  if (faisceauCoupe != obstacle) {
    obstacle = faisceauCoupe;
    digitalWrite(LED_BUILTIN, obstacle ? LOW : HIGH);
    Serial.println(obstacle ? "Faisceau coupe : objet detecte !" : "Faisceau retabli");
    if (obstacle) {
      analogWrite(PIN_BUZZER, VOLUME_BUZZER);
      buzzerActif = true;
      debutBuzzer = millis();
    }
  }

  // Arret buzzer 
  if (buzzerActif && millis() - debutBuzzer >= DUREE_BUZZER_MS) {
    analogWrite(PIN_BUZZER, 0);
    buzzerActif = false;
  }
}
