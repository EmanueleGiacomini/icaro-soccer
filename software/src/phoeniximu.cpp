/**
 * @brief
 *
 * @file phoeniximu.cpp
 * @author your name
 * @date 2018-04-11
 */

#include "phoeniximu.h"

PhoenixImu::PhoenixImu() : _bno(55)
{
    _heading = 0;
}

bool PhoenixImu::inizializza()
{
/**
 * @brief inizializza la comunicazione con l'IMU
 *
 */
return _bno.begin();
}

void PhoenixImu::elabora()
{
   /**
    * @brief Richiede i dati dalla imu e si calcola
    * il nord virtuale
    */
    sensors_event_t event;
    // event -> orientation.x -> heading
    _bno.getEvent(&event);
    _heading=circConstraint(event.orientation.x,-180,180);

}

double PhoenixImu::getHeading()
{
    /**
     * @brief Get the Heading object
     *
     * @return double
     */
    return _heading;
}
