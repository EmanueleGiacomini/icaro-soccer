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
    _blocks= pixy.getBlocks();
    return _blocks;
}
    
bool PixyTracker::findBall() {
    /**
     * @brief Cerca nei blocchi trovati, la signature della palla
     * 
     * @return true la signature della palla e' stata riconosciuta
     * @return false altrimenti
     */
   for (int i=0; i<_blocks; i++){
   
	if (_pixy.blocks[i]==BALL_SIGNATURE){
     _bal_x= _pixy.blocks[i].x;
     _bal_y= _pixy.blocks[i].y;
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
  if (_pixy.blocks[i]==EGOAL_SIGNATURE){
    _goal_x= _pixy.blocks[i].x;
    _goal_y= _pixy.blocks[i].y;
	_egoal_flag=true;
	 return true;	
	}
	
  if (_pixy.blocks[i]==FGOAL_SIGNATURE){
    _goal_x= _pixy.blocks[i].x;
    _goal_y= _pixy.blocks[i].y;
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
     pixy.init();
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
   
   return ball_flag;
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
    return false;
}
    
uint16_t PixyTracker::getBallY() {
    /**
     * @brief Restituisce la coordinata Y della palla
     * 
     * @return uint16_t 
     */
    return _ball_y;
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
    return _goal_x;
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
    return _goal_y;
    return false;
}
