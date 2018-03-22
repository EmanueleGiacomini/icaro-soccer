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

LineSensor::LineSensor() {

}
void LineSensor::inizializza(int* pass) {

}
/**
 * Salva in _output la lettura digitalizzata nel seguente modo:
 * if lettura[i] > soglia[i]:
 *      _output[i] = 1
 * else:
 *      _output[i] = -1
 */
void LineSensor::leggiLinea() {

}
/**
 * Salva in dest le letture calcolate nel seguente format:
 * if _output[i] != -1:
 *    dest[i] = _pass[i]*_output[i]
 * else:
 *    dest[i] = -1
 * @param  dest Array dove salvare l'output del sensore.
 */
void LineSensor::getOutput(int* dest) {

}
/**
 * Attiva la flag di calibrazione
 */
void LineSensor::calibraStart() {

}
/**
 * Disattiva la flag di calibrazione e calcola le soglie
 * tramite le letture effettuate.
 */
void LineSensor::calibraStop() {

}
/**
 * Copia le soglie da src (dim=4) in _soglie
 */
void LineSensor::setSoglie(int* src) {

}
/**
 * Salva in dest gli elementi di _soglie
 * @param  dest Array dove salvare le soglie.
 */
void LineSensor::getSoglie(int* dest) {

}


LineHandler::LineHandler() {

}

void LineHandler::updateTTL() {

}

void LineHandler::inizializza(LineSensor* ls) {

}
/**
 * Richiede i dati dai sensori collegati, cerca i pattern di linee
 * ed aggiorna eventualmente le variabili di fuga (_escapeflag, _escape_dir, _ttl)
 * Il format per riconsocere un pattern di linea e' descritto nel file
 * /icaro-soccer/software/reference/Tesina_2.pdf [pag=39, sez=2.3.6 ]
 */
void LineHandler::elabora() {

}
/**
 * Interroga la classe per conoscere lo status di _escapeflag
 * @return valore di _escapeflag
 */
int LineHandler::getStatus() {

}
/**
 * Restituisce un valore utile solo se _escapeflag e' attiva.
 * @return _escape_dir
 */
int LineHandler::getDirezioneFuga() {
  return -1;
}

/**
 * @return il valore di _ttl
 */
unsigned int LineHandler::getTTL() {
  return 0;
}
