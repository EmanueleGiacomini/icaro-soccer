/**
 * linelib.cpp
 * libreria per la gestione dei sensori di linea
 * Phoenix Soccer 2018
 *
 * La libreria include le classi LineSensor e LineHandler:
 * LineSensor: Interfaccia diretta con il sensore con metodi di scambio dati e calibrazione
 * LineHandler: Interaccia con LineSensor per gestire la rilevazione di linea.
 */

#include "linelib.h"

/* =================================== LineSensor =================================== */

int LineSensor::readSensor(int index) {
  if(index >= 0 && index < 4) return _ads.readADC_SingleEnded(index);
  return -1;
}

LineSensor::LineSensor(int addr) : _ads(addr) {
  _calflag = false;
  vecSet(_output, 4, 0);
  vecSet(_soglie, 4, 0);
  vecSet(_min, 4, 0);
  vecSet(_max, 4, 0);
}

void LineSensor::inizializza(int* pass) {
  _pass = pass;
  _ads.begin();
}

void LineSensor::read() {
  if(_calflag) {
    // Fase di calibrazione
    for(int i = 0; i < 4; i++) {
      int lettura = readSensor(i);
      if(lettura > _max[i]) _max[i] = lettura;
      if(lettura < _min[i]) _min[i] = lettura;
    }    
  } else {
    // Fase di creazione output
    for(int i = 0; i < 4; i++) {
      if(readSensor(i) > _soglie[i]) _output[i] = _pass[i];
      else _output[i] = -1;
    }
  }
}

void LineSensor::getOutput(int* dest) {
  vecCpy(_output, dest, 4);
}

void LineSensor::calibraStart() {
  _calflag = true;
}

void LineSensor::calibraStop() {
  // Calcolo soglie
  for(int i = 0; i < 4; i++) {
    _soglie[i] = (_max[i] + _min[i]) / 2;
  }
  _calflag = false;
}

void LineSensor::setSoglie(int* src) {
  vecCpy(src, _soglie, 4);
}

void LineSensor::getSoglie(int* dest) {
  vecCpy(_soglie, dest, 4);
}

/* =================================== LineHandler =================================== */

void LineHandler::updateTTL() {
  _ttl = (DEFAULT_TTL - (millis() - _line_millis));
}

void LineHandler::reset() {
  _ttl = DEFAULT_TTL;
  _escapeflag = false;
  matSet((int**)_sensori_visti, 4, 0);
  _somma_x = 0;
  _somma_y = 0;
}


void LineHandler::correggi(int dir) {
  _ttl = DEFAULT_TTL;
  _line_millis = millis();
  _escapeflag = true;
  _escape_dir = dir;
}

LineHandler::LineHandler() {

}

void LineHandler::inizializza(LineSensor* ls) {
  _ls = ls;
}

void LineHandler::elabora() {
  int letture[4];
  for(int i = 0; i < 4; i++) {
    _ls->read();
    _ls->getOutput(letture);
    for(int j = 0; j < 4; j++) {
      if(letture[j] != -1) {
        // Un sensore ha rilevato la linea.
        if(_sensori_visti[i][j] != -1) {
          // Il sensore non e' stato considerato precedentemente
          _sensori_visti[i][j] = 1;
          double rad_pos = toRad(letture[j]);
          _somma_x += cos(rad_pos);
          _somma_y += sin(rad_pos);

          int computed_dir = atan2(_somma_y, _somma_x);
          computed_dir = circConstraint(toDeg(computed_dir) + 180, 0, 360);
          correggi(computed_dir);
        }
      }
    }
  }
}

int LineHandler::getFlag() {
  return _escapeflag;
}

int LineHandler::getDirezioneFuga() {
  return _escape_dir;
}

int LineHandler::getTTL() {
  return _ttl;
}
