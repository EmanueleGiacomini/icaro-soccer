
# Icaro Soccer
Questo repository contiene tutti i dati riguardo alla progettazione di hardware e software per i robot calciatori sviluppati nel corso **Icaro** tenuto nell'instituto tecnico industriale **Pacinotti-Archimede** di Roma.


## Struttura repository
Entrambe le sottocartelle di software e hardware contengono una cartella **_reference_** contenente ideè e link utili per la progettazione.
### Software
Ogni sottocartella è composta da un file di estensione **ino** che contiene il programma da inserire in Arduino, e da una cartella
**src** che contiene le librerie utilizzate dal programma.

Le librerie presenti sono:
-**comlib** : libreria che gestisce la comunicazione fra i vari microcontrollori.
-**motlib** : libreria che contiene algoritmi per i motori.
-**sreglib** : libreria per la gestione dello _shift register_.
-**strlib** : libreria per la manipolazione di stringhe.
-**veclib** : liberia per la manipolazione di vettori e matrici

### Hardware
La sottocartella **drawings** contiene i disegni tecnici relativi alla struttura del robot.
**electronics** conterrà i disegni relativi ai circuiti stampati realizzati con EAGLE.
