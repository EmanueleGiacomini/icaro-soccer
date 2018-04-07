/**
 * linelib.h
 * libreria per la gestione dei sensori di linea
 * Phoenix Soccer 2018
 *
 * La libreria include le classi LineSensor e LineHandler:
 * LineSensor: Interfaccia diretta con il sensore con metodi di scambio dati e calibrazione
 * LineHandler: Interaccia con LineSensor per gestire la rilevazione di linea.
 */

#ifndef linelib_h
#define linelib_h
#include <Adafruit_ADS1015.h>
#include "veclib.h"
#include "phoenixutil.h"


#define DEFAULT_TTL 3000

class LineSensor {
  /**
   * @brief LineSensor si interfaccia direttamente con il modulo
   * sensore-linea composto da un ADC ADS1115 con interfaccia i2C
   * e 4 sensori di linea (coppia fototransistor - led).
   * Tramite i metodi forniti, e' possibile calibrare il modulo per
   * ottenere un output digitalizzato.
   */

  bool _calflag = false;  // Flag di calibrazione
  int* _pass; // Array di posizioni associate per ogni sensore.
  int _output[4]; // Array contenente l'output relativo ai sensori.
  int _soglie[4]; // Array contenente le soglie relative ai sensori.
  int _min[4];  // Array dei minimi individuati
  int _max[4];  // Array dei massimi individuati
  Adafruit_ADS1015 _ads;

  /**
   * @brief Interroga il modulo sensore-linea per ottenere
   * la lettura analogica di uno specifico sensore 
   * @param index indice del sensore richiesto (0 < index < 4)
   * @return int valore analogico letto dal sensore richiesto.
   * Il valore -1 corrisponde ad un errore.
   */
  int readSensor(int index);
public:
  LineSensor(int addr);
  /**
   * @brief Inizializza la comunicazione con ADS1115 ed assegna
   * ad ogni sensore una posizione.
   * 
   * @param addr Indirizzo del ADS1115
   * @param pass Array di posizioni associate per i sensori
   */
  void inizializza(int* pass);
  /**
   * @brief Richiede le letture analogiche dal modulo, e ne effettua
   * il confronto con l'array di soglie interno.
   * Il risultato viene poi salvato. e puo' essere richiesto tramite
   * il metodo getOutput 
   */
  void read();
  /**
   * @brief Copia in un array fornito, quali sensori vedono
   * istantaneamente la linea.
   * Un valore pari a -1 indica l'assenza di linea sul sensore
   * specifico
   * 
   * @param dest Array dove scrivere i risultati.
   * NB: La dimensione di dest deve essere superiore o uguale a 4
   */
  void getOutput(int* dest);
  /**
   * @brief Attiva la modalita' di calibrazione, durante questa fase,
   * invocando il metodo read, i sensori si calibreranno per poter
   * riconoscere la linea bianca presente sul campo.
   * Durante la fase di calibrazione, ogni sensore deve essere
   * ben esposto alla linea, ed al campo di gioco, per questo si
   * consiglia un periodo di calibrazione di circa 10 secondi. 
   * NB: Le soglie non verranno aggiornate fino alla chiusura 
   * della fase di calibrazione.
   */
  void calibraStart();
  /**
   * @brief Chiude la fase di calibrazione e, ricalcola la nuova
   * soglia per ogni sensore.
   */
  void calibraStop();
  /**
   * @brief E' possibile impostare le soglie tramite un array esterno
   * da cui leggere i valori da impostare.   * 
   * @param src Array sorgente da cui leggere le soglie da impostare.
   * NB: La dimensione di src deve essere superiore o uguale a 4
   */
  void setSoglie(int* src);
  /**
   * @brief E' possibile leggere le soglie calcolate, fornendo un array
   * dove scrivere tali informazioni.
   * 
   * @param dest Array di destinazione su cui scrivere le soglie.
   * NB: La dimensione di dest deve essere superiore o uguale a 4
   */
  void getSoglie(int* dest);
};



class LineHandler {
  /**
   * @brief LineHandler si comporta come interfaccia generale per
   * la gestione della rilevazione linee. Tramite i metodi forniti
   * e' possibile capire quando il robot si trova in prossimita di
   * una linea di campo.
   * LineHandler in oltre può restituire una direzione ed un
   * tempo ottimale per la fuga.
   */

  LineSensor* _ls; // Array di LineSensor
  
  bool _escapeflag = 0; // Flag di avviso rilevazione linea.
  int _escape_dir; // Traiettoria di fuga
  int _ttl; // Time-To-Live della traiettoria di fuga
  unsigned long _line_millis;
  
  // Variabili per interpolazione linea.
  double _somma_x = 0;
  double _somma_y = 0;
  int _sensori_visti[4][4];

  /**
   * @brief Aggiorna il Time-To-Live della rilevazione
   * di linea. 
   */
  void updateTTL();

  /**
   * @brief Resetta la flag di rilevazione, e tutte le variabili intere
   * dedicate al riconoscimento della linea. 
   */
  void reset();

  /**
   * @brief Attiva la flag di correzione, stabilisce una direzione
   * di fuga e resetta il TTL della rilevazione.
   * 
   * @param dir direzione di fuga da impostare.
   */
  void correggi(int dir);

public:
  LineHandler();
  /**
   * @brief Stabilisce il collegamento fra LineHandler e
   * gli oggetti LineSensor del robot.
   * 
   * @param ls Array di LineSensor del robot.
   * NB: la dimensione di ls deve essere pari a 4
   */
  void inizializza(LineSensor* ls);
  /**
   * @brief Dopo aver richiesto i dati dai LineSensor, ricerca eventuali
   * pattern riconducibili ad una linea. In caso di rilevazione, attiva
   * la escape_flag, ed imposta la direzione di fuga ottimale.
   */
  void elabora();
  /**
   * @brief Restituisce escape_flag
   * 
   * @return int 
   */
  int getFlag();
  /**
   * @brief Restituisce la direzione di fuga ottimale
   * 
   * @return int 
   */
  int getDirezioneFuga();
  /**
   * @brief Restituisce il TTL della rilevazione
   * 
   * @return int 
   */
  int getTTL();
};

#endif
