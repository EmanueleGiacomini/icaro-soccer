/* FUNZIONE MOTORE PURAMENTE ROTATIVA ( velocità negativa lo fà ruotare a sinistra, velocità positiva a destra.)
*/


/*
se prendo una linea mi imposto una variabile che contiene la direzione della correzione a quel punto se il robot viene spinto fuori 
e prende le linee dall'altra parte che vorrebbero farlo andare fuori, lui ricontrolla la suddetta variabile e non corregge 

questa var. viene azzerata se non leggo nessuna linea negli ultimi X secondi

la variabile viene aggiornata solo se la nuova correzione è compresa entro un certo range


*/