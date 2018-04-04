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


#define DEFAULT_TTL 3000

class LineSensor {
  /**
   * [LineSensor description]
   */
  bool _calflag = false;  // Flag di calibrazione
  int* _pass; // Array di posizioni associate per ogni sensore.
  int _output[4]; // Array contenente l'output relativo ai sensori.
  int _soglie[4]; // Array contenente le soglie relative ai sensori.
public:
  LineSensor();
  void inizializza(int* pass);
  /**
   * Salva in _output la lettura digitalizzata nel seguente modo:
   * if lettura[i] > soglia[i]:
   *      _output[i] = 1
   * else:
   *      _output[i] = -1
   */
  void leggiLinea();
  /**
   * Salva in dest le letture calcolate nel seguente format:
   * if _output[i] != -1:
   *    dest[i] = _pass[i]*_output[i]
   * else:
   *    dest[i] = -1
   * @param  dest Array dove salvare l'output del sensore.
   */
  void getOutput(int* dest);
  /**
   * Attiva la flag di calibrazione
   */
  void calibraStart();
  /**
   * Disattiva la flag di calibrazione e calcola le soglie
   * tramite le letture effettuate.
   */
  void calibraStop();
  /**
   * Copia le soglie da src (dim=4) in _soglie
   */
  void setSoglie(int* src);
  /**
   * Salva in dest gli elementi di _soglie
   * @param  dest Array dove salvare le soglie.
   */
  void getSoglie(int* dest);
};



class LineHandler {
  /**
   * Chiamando elabora, LineHandler chiama tutti i sensori ed elabora le letture
   * per cercare eventuali patter di linea.
   * Se individua una linea, attiva _escapeflag, fornisce la
   * direzione di fuga tramite _escape_dir ed imposta un timer _TTL (ms)
   * ad un intervallo prestabilito
   */
  LineSensor* _ls;  //Array di LineSensor a cui interfacciarsi.
  bool _escapeflag = 0; // Flag di avviso rilevazione linea.
  int _escape_dir;  // Traiettoria di fuga
  unsigned int _ttl;// Time-To-Live della traiettoria di fuga
  /**
   * Aggiorna il timer _ttl, se raggiunge lo 0, _escapeflag andrà disabilitata
   */
  void updateTTL();
public:
  LineHandler();
  void inizializza(LineSensor* ls);
  /**
   * Richiede i dati dai sensori collegati, cerca i pattern di linee
   * ed aggiorna eventualmente le variabili di fuga (_escapeflag, _escape_dir, _ttl)
   * Il format per riconsocere un pattern di linea e' descritto nel file
   * /icaro-soccer/software/reference/Tesina_2.pdf [pag=39, sez=2.3.6 ]
   */
  void elabora();
  /**
   * Interroga la classe per conoscere lo status di _escapeflag
   * @return valore di _escapeflag
   */
  int getStatus();
  /**
   * Restituisce un valore utile solo se _escapeflag e' attiva.
   * @return _escape_dir
   */
  int getDirezioneFuga();

  /**
   * @return il valore di _ttl
   */
  unsigned int getTTL();
};

#endif
