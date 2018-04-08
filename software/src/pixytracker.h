/**
 * @brief 
 * 
 * @file PixyTracker.h
 * @author your name
 * @date 2018-04-08
 */

#ifndef PixyTracker_h
#define PixyTracker_h

#include <Arduino.h>
#include <SPI.h>
#include <Pixy.h>



#define BALL_SIGNATURE 0x01
#define EGOAL_SIGNATURE 0x02
#define FGOAL_SIGNATURE 0x03

class PixyTracker {
    /**
     * @brief PixyTracker e' un interfaccia personalizzata per PixyCam
     * tramite la quale e' possibile determinare la posizione di palla e 
     * porte (alleata e nemica).
     */
    bool _ball_flag, _egoal_flag, _fgoal_flag;
    //uint16_t : unsigned short (2 byte int)
    uint16_t _ball_x, _ball_y;
    uint16_t _goal_x, _goal_y;
    Pixy _pixy;

    /**
     * @brief Interroga Pixy per sapere quanti oggetti
     * attualmente sono nel suo campo visivo
     * 
     * @return int numero di blocchi attualmente visibili
     */
    int getPixyData();
    /**
     * @brief Cerca nei blocchi trovati, la signature della palla
     * 
     * @return true la signature della palla e' stata riconosciuta
     * @return false altrimenti
     */
    bool findBall();
    /**
     * @brief Cerca nei blocchi trovati, la signature della porta alleata,
     * o la porta nemica
     * NB: Per sapere quale porta e' stata individuata, guardare _egoal_flag
     * ed _fgoal_flag
     * 
     * @return true una delle signature e' stata riconosciuta
     * @return false altrimenti
     */
    bool findGoal();

public:
    PixyTracker();
    /**
     * @brief Inizializza la comunicazione con PixyCam
     */
    void inizializza(); 
    /**
     * @brief Interroga Pixy e cerca nella risposta eventuali elementi importanti (palla, porte)
     */
    void elabora();
    /**
     * @brief Restituisce lo stato di visione sulla palla
     * 
     * @return true Se la palla e' nel raggio visivo della Pixy
     * @return false altrimenti
     */
    bool getBallStatus();
    /**
     * @brief Restituisce lo stato di visione sulla porta nemica
     * 
     * @return true Se la porta nemica e' nel raggio visivo della Pixy
     * @return false altrimenti
     */
    bool getEGoalStatus();
    /**
     * @brief Restituisce lo stato di visione sulla porta alleata
     * 
     * @return true Se la porta alleata e' nel raggio visivo della Pixy 
     * @return false altrimenti
     */
    bool getFGoalStatus();

    /**
     * @brief Restituisce la coordinata X della palla
     * 
     * @return uint16_t 
     */
    uint16_t getBallX();
    /**
     * @brief Restituisce la coordinata Y della palla
     * 
     * @return uint16_t 
     */
    uint16_t getBallY();
    /**
     * @brief Restituisce la coordinata X della porta
     * NB: Le coordinate ( X, Y ) della porta, si riferiscono
     * a una delle due porte correntemente visibili dalla Pixy,
     * per sapere a quale porta si riferisce, usare getEGoalStatus
     * e getFGoalStatus
     * 
     * @return uint16_t 
     */
    uint16_t getGoalX();
    /**
     * @brief Restituisce la coordinata Y della porta
     * NB: Le coordinate ( X, Y ) della porta, si riferiscono
     * a una delle due porte correntemente visibili dalla Pixy,
     * per sapere a quale porta si riferisce, usare getEGoalStatus
     * e getFGoalStatus
     * 
     * @return uint16_t 
     */
    uint16_t getGoalY();    
};

#endif