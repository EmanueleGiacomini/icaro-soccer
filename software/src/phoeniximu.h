/**
 * @brief
 *
 * @file phoeniximu.h
 * @author your name
 * @date 2018-04-11
 */

#ifndef phoeniximu_h
#define phoeniximu_h

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "phoenixutil.h"



class PhoenixImu {
    /**
    * @brief
    *
    */
    Adafruit_BNO055 _bno;
    double _heading;
public:
    PhoenixImu();
    /**
     * @brief inizializza la comunicazione con l'IMU
     *
     */
    bool inizializza();
    /**
     * @brief Richiede i dati dalla imu e si calcola
     * il nord virtuale
     */
    void elabora();
    /**
     * @brief Get the Heading object
     *
     * @return double
     */
    double getHeading();
};

#endif
