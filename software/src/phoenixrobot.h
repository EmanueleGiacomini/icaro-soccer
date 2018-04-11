/**
 * @brief 
 * 
 * @file phoenixrobot.h
 * @author your name
 * @date 2018-04-11
 */

#ifndef phoenixrobot_h
#define phoenixrobot_h

#include <Arduino.h>
#include "phoeniximu.h"
#include "linelib.h"
#include "motlib.h"
#include "pixytracker.h"

// TODO: Inserire PID

class PhoenixRobot {
    PixyTracker* _pixy;
    PhoenixImu* _imu;
    LineHandler* _lh;
    Piattaforma* _p;
public:
    PhoenixRobot();

    void inizializza(PixyTracker* pixy, PhoenixImu* imu, LineHandler* lh, Piattaforma* p);
    /**
     * @brief Richiede i dati dai sensori multipli del robot.
     * 
     */
    void elabora();
    /**
     * @brief guarda nella direzione della palla
     * 
     * @return true il robot sta eseguendo la correzione
     * @return false correzione conclusa
     */
    bool trackBall();
    /**
     * @brief guarda nella direzione del nord virtuale
     * 
     * @return true il robot sta eseguendo la correzione
     * @return false correzione conclusa
     */
    bool trackNorth();
    /**
     * @brief guarda nella direzione della porta nemica
     * 
     * @return true il robot sta eseguendo la correzione
     * @return false correzione conclusa
     */
    bool trackGoal();
    /**
     * @brief Si muove in modo da allineare la palla con la porta avversaria
     * 
     * @return true il robot sta eseguendo la correzione
     * @return false correzione conclusa
     */
    bool alignBallGoal();
    /**
     * @brief Esegue la routine di fuga dalla linea per rimanere all'interno
     * del campo
     * 
     * @param dir direzione di fuga
     * @return true il robot sta eseguendo la correzione
     * @return false correzione conclusa
     */
    bool  correggiLinea(int dir);






};

#endif