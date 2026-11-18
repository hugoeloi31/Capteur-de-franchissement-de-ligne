/*********************************************************************
 * @file  Apllication.h
 * @author ELOI Hugo & CHABA Abdelhak
 * @brief Fichier header de l'application Capteur de franchissement de ligne
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <IRremoteESP8266.h>
#include <IRsend.h>

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);

  private :
    IRsend emetteurIR;
    bool obstacle;
    int nbSansSignal;
};
#endif