/**
 * @brief PixyTracker e' un interfaccia personalizzata per PixyCam
 * tramite la quale e' possibile determinare la posizione di palla e 
 * porte (alleata e nemica).
 * 
 * @file pixytracker.cpp
 * @author your name
 * @date 2018-04-08
 */

#include "pixytracker.h"

int PixyTracker::getPixyData() {
    /**
     * @brief Interroga Pixy per sapere quanti oggetti
     * attualmente sono nel suo campo visivo
     * 
     * @return int numero di blocchi attualmente visibili
     */

    return 0;
}
    
bool PixyTracker::findBall() {
    /**
     * @brief Cerca nei blocchi trovati, la signature della palla
     * 
     * @return true la signature della palla e' stata riconosciuta
     * @return false altrimenti
     */

    return false;
}
    
bool PixyTracker::findGoal() {
    /**
     * @brief Cerca nei blocchi trovati, la signature della porta alleata,
     * o la porta nemica
     * NB: Per sapere quale porta e' stata individuata, guardare _egoal_flag
     * ed _fgoal_flag
     * 
     * @return true una delle signature e' stata riconosciuta
     * @return false altrimenti
     */

    return false;
}

PixyTracker::PixyTracker() {

}
    
void PixyTracker::inizializza() {
    /**
     * @brief Inizializza la comunicazione con PixyCam
     */
}
    
void PixyTracker::elabora() {
    /**
     * @brief Interroga Pixy e cerca nella risposta eventuali elementi importanti (palla, porte)
     */
}
    
bool PixyTracker::getBallStatus() {
    /**
     * @brief Restituisce lo stato di visione sulla palla
     * 
     * @return true Se la palla e' nel raggio visivo della Pixy
     * @return false altrimenti
     */

    return false;
}
    
bool PixyTracker::getEGoalStatus() {
    /**
     * @brief Restituisce lo stato di visione sulla porta nemica
     * 
     * @return true Se la porta nemica e' nel raggio visivo della Pixy
     * @return false altrimenti
     */

    return false;
}
    
bool PixyTracker::getFGoalStatus() {
    /**
     * @brief Restituisce lo stato di visione sulla porta alleata
     * 
     * @return true Se la porta alleata e' nel raggio visivo della Pixy 
     * @return false altrimenti
     */

    return false;
}


    
uint16_t PixyTracker::getBallX() {
    /**
     * @brief Restituisce la coordinata X della palla
     * 
     * @return uint16_t 
     */

    return false;
}
    
uint16_t PixyTracker::getBallY() {
    /**
     * @brief Restituisce la coordinata Y della palla
     * 
     * @return uint16_t 
     */

    return false;
}
    
uint16_t PixyTracker::getGoalX() {
    /**
     * @brief Restituisce la coordinata X della porta
     * NB: Le coordinate ( X, Y ) della porta, si riferiscono
     * a una delle due porte correntemente visibili dalla Pixy,
     * per sapere a quale porta si riferisce, usare getEGoalStatus
     * e getFGoalStatus
     * 
     * @return uint16_t 
     */

    return false;
}
    
uint16_t PixyTracker::getGoalY() {
    /**
     * @brief Restituisce la coordinata Y della porta
     * NB: Le coordinate ( X, Y ) della porta, si riferiscono
     * a una delle due porte correntemente visibili dalla Pixy,
     * per sapere a quale porta si riferisce, usare getEGoalStatus
     * e getFGoalStatus
     * 
     * @return uint16_t 
     */

    return false;
}