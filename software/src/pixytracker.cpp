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
    uint32_t current_millis = millis();
    if(current_millis - _call_millis > COM_INTERVAL) {          //eseguo la funzione una volta ogni 10 millisecondi
        _blocks = _pixy.getBlocks();
        _call_millis = current_millis;
        return _blocks;
    }
}

bool PixyTracker::findBall() {
    /**
     * @brief Cerca nei blocchi trovati, la signature della palla
     *
     * @return true la signature della palla e' stata riconosciuta
     * @return false altrimenti
     */
   for (int i=0; i<_blocks; i++){

	if (_pixy.blocks[i].signature==BALL_SIGNATURE){
     _ball_x= _pixy.blocks[i].x;
     _ball_y= _pixy.blocks[i].y;
     _ball_w = _pixy.blocks[i].width;
     _ball_h = _pixy.blocks[i].height;
	 _ball_flag=true;
	 return true;
	}
  }
  _ball_flag=false;
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
 for (int i=0; i<_blocks; i++){
  if (_pixy.blocks[i].signature==EGOAL_SIGNATURE){
    _goal_x= _pixy.blocks[i].x;
    _goal_y= _pixy.blocks[i].y;
    _goal_h = _pixy.blocks[i].height;
    _goal_w = _pixy.blocks[i].width;
	_egoal_flag=true;
	 return true;
	}

  if (_pixy.blocks[i].signature==FGOAL_SIGNATURE){
    _goal_x= _pixy.blocks[i].x;
    _goal_y= _pixy.blocks[i].y;
    _goal_h = _pixy.blocks[i].height;
    _goal_w = _pixy.blocks[i].width;
	_fgoal_flag=true;
	return true;
	}
  }
  _fgoal_flag=false;
  _egoal_flag=false;
  return false;
}
PixyTracker::PixyTracker() {

}

void PixyTracker::inizializza() {
    /**
     * @brief Inizializza la comunicazione con PixyCam
     */
    _pixy.init();
}

void PixyTracker::elabora() {
    /**
     * @brief Interroga Pixy e cerca nella risposta eventuali elementi importanti (palla, porte)
     */
   getPixyData();
   findBall();
   findGoal();
}

bool PixyTracker::getBallStatus() {
    /**
     * @brief Restituisce lo stato di visione sulla palla
     *
     * @return true Se la palla e' nel raggio visivo della Pixy
     * @return false altrimenti
     */

   return _ball_flag;
}

bool PixyTracker::getEGoalStatus() {
    /**
     * @brief Restituisce lo stato di visione sulla porta nemica
     *
     * @return true Se la porta nemica e' nel raggio visivo della Pixy
     * @return false altrimenti
     */

   return _egoal_flag;
}

bool PixyTracker::getFGoalStatus() {
    /**
     * @brief Restituisce lo stato di visione sulla porta alleata
     *
     * @return true Se la porta alleata e' nel raggio visivo della Pixy
     * @return false altrimenti
     */
   return _fgoal_flag;
}



uint16_t PixyTracker::getBallX() {
    /**
     * @brief Restituisce la coordinata X della palla
     *
     * @return uint16_t
     */
    return _ball_x;
}

uint16_t PixyTracker::getBallY() {
    /**
     * @brief Restituisce la coordinata Y della palla
     *
     * @return uint16_t
     */
    return _ball_y;
}

uint16_t PixyTracker::getBallHeight() {
    /**
     * @brief Restituisce l'altezza della palla
     *
     * @return uint16_t
     */
    return _ball_h;
}

uint16_t PixyTracker::getBallWidth() {
    /**
     * @brief Restituisce la larghezza della palla
     *
     * @return uint16_t
     */
    return _ball_w;
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
    return _goal_x;
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
    return _goal_y;
}

uint16_t PixyTracker::getGoalHeight() {
    /**
     * @brief Restituisce l'altezza della porta
     *
     * @return uint16_t
     */
    return _goal_h;
}

uint16_t PixyTracker::getGoalWidth() {
    /**
     * @brief Restituisce la larghezza della porta
     *
     * @return uint16_t
     */
    return _goal_w;
}
