# Interpretazione vs traduzione

Traduzione:
- sostituisce il linguaggio con un linguaggio di livello inferiore
	- compilazione:
		- traduce tutte le istruzioni in linguaggio macchina creando un file eseguibile
		- vantaggi:
			- più veloce perché crea un file eseguibile immediatamente utilizzabile dal processore e in momenti futuri

Interpretazione:
- traduce ed esegue ogni singola istruzione del programma in modo sequenziale.
	- vantaggi:
		-  riparare il codice 
		- aggiungere nuove istruzioni
		- strutturare e documentare le istruzioni complesse

# Livelli del computer

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img1.png|center|300]]

# CPU

- Da 1 a 32 registri
- ALU -> esegue istruzioni di somma e sottrazione
- bus di interconnessione

tipi di operazioni:
- istruzioni registro-memoria: prelievo di parole in memoria e portate nei registri, utilizzate dalla alu per operazioni successive
- istruzioni registro-registro: preleva due operandi dai registri e li porta nei registri di input della ALU e memorizza il risultato in uno dei due registri

# ciclo dell'esecuzione
- prelievo istruzione successiva dalla memoria e portata nell'IR
- modifica PC per farlo puntare a successiva istruzione
- determinare tipo di istruzione
- determinare zona di memoria se si utilizza una parola
- prelevare la parola e portarla nella CPU
- eseguire istruzione
- tornare al punto 1

# CISC
- complex istruction set computer
- set di istruzioni in grado di eseguire istruzioni più complesse 
- con una sola istruzione si può: leggere dato in memoria, modificarlo e salvarlo
- vantaggi:
	- programmi più compatti
	- ogni set di istruzioni ha oltre 300 istruzioni separate
- svantaggi:
	- programmi più pesanti 
	- maggior tempo per l'esecuzione

# RISC
permette al microprocessore di eseguire il set di istruzioni in tempi rapidi. Istruzioni semplici e della stessa lunghezza


# RAID
migliora prestazioni e affidabilità dei dischi. 
5 schemi:
- RAID 0: dati suddivisi in strisce su n settori con modalita round-robin. Un blocco dati può essere scritto con 4 letture parallele. 
	- svantaggi:
		- lavora male se vengono richiesti dati di uno stesso settore
		- perdita di dati in caso di rottura del disco
- RAID 1: stesso funzionamento di RAID 0 ma dischi duplicati  per backup.
- RAID 2: utilizza byte per decomporre le informazioni sui dischi. con 7 dischi si può dividere un bit per disco. I byte si dividono in 4 bit e si aggiungono 3 bit per correzione di hamming. Se si rompe un disco si ricostruisce facilmente. Operazioni svolte in parallelo
- RAID 3: verisone semplificata di RAID 2. un solo bit di partià scritto in un disco di parità. Non offre affidabilità sugli errori (1 bit non è sufficiente)
- RAID 4 e 5: lavorano su strisce e non richiedono dischi sincronizzati con una parità per striscia scritta su un disco separato di parità. Si esegue l’EXOR bit a bit di tutte le strisce ottenendo così una striscia di parità.

# Multiplexer
Circuito con $2^n$ dati di input, un valore di output ed n input di controllo. Gli input selezionano la linea in ingresso (una sola ad 1 le restanti n-1 a 0) che verrà trasferita in uscita.

# Decoder
Accetta come input un numero ad n bit e lo utilizza per impostare ad 1 una sola delle $2^n$ linee di output

# PLA
Chip che permette di calcolare somme di prodotti

# Shifter
Circuito con n input, n output ed un bit di controllo. Permette di traslare di una posizione a destra o sinistra in base al valore del bit c (1 =  dx, 0 = sx)

# Sommatori
Per calcolare somme tra bit. Realizzato utilizzando n sommatori (prende in ingresso 3 bit A, B e riporto in ingresso), realizzati a loro volta da 2 semi-sommatori (solo per i bit meno significativi, non gestisce riporto in ingresso)

# Clock
Circuito che emette impulsi di larghezza definita ad intervalli di tempo costanti. L'intervallo di tempo tra le estremità di due impulsi è detto tempo di ciclo di clock.
La frequenza di clock specifica il numero di cicli per unità di tempo

# Latch SR
Due NOR con le uscite retroazionati in ingresso. Ha due valori di ingresso S (set) utilizzato per impostare ad 1 il valore di uscita e R (reset) utilizzato per azzerarlo.
Quando S è impostato ad 1 lo stato del latch è Q = 1 indipendentemente dallo stato precedente. Quando R si imposta ad 1, il latch passa nello stato Q = 0

# Latch SR temporizzato
I segnali agiscono solo quando il segnale di clock è attivo. Quando il clock vale 0, le AND bloccano i segnali S ed R ed il latch non può cambiare stato. Quando il clock vale 1, le porte AND non sono bloccate e il latch continua a funzionare normalmente

# D Latch temporizzato
Per risolvere le ambiguità del latch sr viene utilizzato un solo dato di ingresso D e un clock. 
- Quando D = 1 e clock = 1, stato latch Q = 1
- Quando D = 0 e clock = 1, stato latch Q = 0

# Flip flop
Circuito simile al latch. Differisce nell'istante in cui il segnale di clock determina il cambiamento di stato:
- Latch: cambiamento di stato è determinato dal livello alto/basso del clock
- Flip flop: cambiamento di stato determinato dal fronte di salita/discesa del clock

# Bus
- collegamento che unisce i vari dispositivi di un computer
- Interni alla CPU (connette registri della ALU) o esterni (memorie e periferiche I/O)
- Dispositivi master: possono iniziare trasferimento dati sul bus
- Dispositivi slave: restano in attesa di una richiesta di un master
- Spesso i segnali generati dalla periferiche sono troppo deboli per alimentare un bus. Per risolvere questo problema i dispositivi sono connessi a dei chip:
	- bus-driver: chip dei dispositivi master
	- bus-receiver: chip dispositivi slave
	- trasmettitore-ricevitore del bus: periferiche con ruolo di master e slave
- un bus con n linee di indirizzi può indirizzare $2^n$ locazioni di memoria
# Bus sincroni
- Clock che determina temporizzazione delle attività sul bus. Ogni operazione richiede un numero di periodi di clock per essere eseguita
	- CPU master pone l'indirizzo di memoria sull'address bus
	- CPU comunica l'operazione che intende fare con la memoria
	- CPU comunica che si tratta di operazione in lettura, la memoria slave deve fornire il contenuto della cella indirizzata dall'address bus

# Bus asincroni
Bus si adatta alla velocità del dispositivo collegato ed un dispositivo lento non rallenterà il sistema

# Arbitraggio del bus
- Ciascun dispositivo del computer può diventare a turno master del bus. L'arbitraggio del bus è utilizzato per prevenire situazioni di conflitto nel caso in cui più dispositivi tentano di diventare master.

## Arbitraggio del bus centralizzato
- Necessita di un albero che quando riceve una richiesta di utilizzo del bus la concede, garantendo una linea di connessione. Quando il dispositivo più vicino la vede:
	- se lo ha richiesto blocca la linea negandola a tutti
	- lascia libera la linea
- Quando due o più dispositivi fanno richiesta la ottiene il dispositivo più vicino all'arbitro

## Arbitraggio del bus decentralizzato
- Ogni dispositivo ha una propria linea di richiesta ed una priorità.
- Prima di inviare una richiesta verifica che non ce ne sia un'altra con priorità più alta.
- Ci sono tre linee:
	- richiesta del bus
	- busy
	- linea di arbitraggio
- Per ottenere un bus un dispositivo deve:
	- controllare che BUSY sia negata e l'ingresso IN asserito
	- nega OUT, asserisce la linea BUSY e diventa il master del bus
	- Al termine sbloca OUT  e libera BUSY negandolo

# Livello di microarchitettura
- Descrive il funzionamento interno di una CPU e come le istruzioni vengono interpretate ed eseguite dall'hardware.

# Percorso dati
- Parte della CPU che contiene la ALU i suoi input ed output. 
- Contiene registri a 32 bit che controllano accesso in memoria
- Due bus: B e C
- I registri possono inviare il proprio contenuto sul bus B collegato in input alla ALU. Alla base della ALU c'è uno shifter che invia il proprio risultato a bus C.
I registri del data path sono:
- MAR (Mem. Addr. Reg.)
- MDR (Mem. Data Reg.)
- PC (Progr. Count.)
- SP (Stack point.)

# ALU
- Contiene un decodificatore che in base ai segnali permette di attivare una delle linee per le operazioni AND, OR, NOT e somma aritmetica
- Contiene un settore con le porte logiche per calcolare AND OR e NOT
- Gli input ENA e ENB sono utilizzati per forzare a 0 gli input A e B
- L'input INVA permette di negare il valore di A
- Contiene un settore con un full-adder
- Le ALU ad 1 bit possono essere assemblate insieme per costruire un'ALU di lunghezza variabile.

# Temporizzazione del percorso dati
- Ogni nuovo ciclo ha inizio sul fronte di discesa del clock. In questo momento vengono memorizzati i bit che controllano il funzionaento delle porte
- Il registro viene selezionato ed il contenuto portato sul bus B
- A questo punto la ALU e lo shifter possono operare sui suoi dati e gli output diventano stabili dopo un intervall di tempo. 
- I risultati sono propagati lungo il bus C e caricati nei registri in corrispondenza del fronte di salita

# Operazioni della memoria
La CPU ha due modi per comunicare con la memoria:
- Porta da 32 bit per lettura/scrittura dei dati. La porta è controllata da due registri:
	- MAR: specifica indirizzo di memoria in cui si desidera leggere/scrivere
	- MDR: ospita la parola che sarà letta o scritta all'indirizzo di memoria specificato da MAR
- Porta ad 8 bit **solo per lettura** del programma eseguibile. Questa porta è controllata da due registri:
	- PC: registro a 32 bit che indica l'indirizzo di memoria della prossima istruzione da caricare
	- MBR: registro a 32 bit che contiene il byte letto (memorizzato negli 8 bit meno significativi) dalla memoria durante il fetch. Può essere scritto sul bus B in due modi:
		- Unsigned: i 24 bit non utilizzati vengono impostati a 0 (valore MBR tra 0 e 255)
		- Signed: il bit di segno (il settimo) viene copiato sui 24 bit non utilizzati (valori tra -128 e +127)

# Microistruzioni
- Per il controllo del data path si utilizzano 29 segnali divisibili in 5 gruppi:
	- 9 segnali per controllare la scrittura dei dati dal bus C all'interno dei registri
	- 9 segnali per controllare l'abilitazione dei registri del bus B per l'input della ALU
	- 8 segnali per controllare le funzioni della ALU e dello shifter
	- 2 segnali per indicare lettura/scrittura della memoria tramite PC/MBR
	- 1 segnale per il fetch delle istruzioni dalla memoria
- I valori di questi segnali specificano il comportamento della CPU da eseguire durante un ciclo del data path.
- La sequenza di cicli di data path necessari all'esecuzione di un'istruzione prende il nome di mircoprogramma. Un microprogramma è costituito di microistruzioni
- I 29 segnali di controllo non sono sufficienti a specificare una microistruzione perché è necessario specificare cosa fare nel ciclo seguente.
- Una microistruzione è una sequenza di bit composta da 3 parti:
	- Control: stato dei sengali di controllo
		- ALU: seleziona le funzioni dell'ALU e dello shifter
		- C: seleziona i registri scritti dal bus C
		- Mem: seleziona la funzione in memoria
		- B: seleziona quale registro è scritto sul bus B
	- Address: indirizzo della prossima microistruzione da eseguire
	- JAM: bit per la gestione dei salit incondizionati

# Microarchitettura MIC-1
- Decisione dei segnali di controllo da abilitare durante ciascun  ciclo è determinato da un sequenzializzatore che si occupa di far avanzare la sequenza delle operazioni per eseguire una singola istruzione.
- Durante ogni ciclo il sequenzailizzatore deve produrre due informazioni:
	- stato di ogni segnale di controllo del sistema
	- indirizzo della microistruzione successiva

# Funzionamento di MIC-1
- All'inizio di ogni ciclo di clock MIR viene caricato con il contenuto della parola indirizzata da MPC. 
- I segnali vengono poi propagati all'interno del data path e uno dei registri viene inviato attraverso il bus B alla ALU che calcola la funzione richiesta e produce sul bus C il risultato.
- Sul fronte di salita i registri selezionati vengono caricati

# Il livello ISA 
- Descrive l'architettura delle istruzioni che la CPU è in grado di eseguire. 
- Ogni CPU ha un proprio ISA e quindi istruzioni diverse spesso non sono compatibili tra loro
- Fa da interfaccia tra compilatori e hardware
- Ha due modalità operative:
	- kernel: per eseguire SO e le istruzioni
	- utente: per eseguire o programmi utente e non operazioni sensibili

# Ortogonalità
- Principio secondo cui ogni istruzione dovrebbe essere in grado di utilizzare qualsiasi modalità di indirizzamento supportata. 
- Fornisce diverse modalità di indirizzamento, consentendo al programmatore di scegliere quella che soddisfa le necessità del programma

# Lo stack
- Struttura utlizzata per memorizzare lo stato di una procedura che segue filosofia LIFO.
- In IJVM è utilizzato per memorizzare variabili ed eseguire calcoli aritmetici. Vengono mantenuti due puntatori a indirizzi di memoria:
	- Puntatore alla base attuale dello stack (LV)
	- Puntatore alla cima (SP - Stack Pointer)

# Modello della memoria IJVM
- La memoria può essere vista come un vettore di:
	- 4.294.967.296 byte (4 GB) 
	- 1.073.741.824 parole da 4 byte 
- L'unico modo che le istruzioni IJVM hanno per accedere alla memoria è quello di indicizzarla utilizzando dei puntatori. Sono definite le aree di memoria:
	- Costant Pool: i programmi IJVM non possono scrivere in quest'area che contiene costanti, stringhe e puntatori ad altre aree di memoria
	- Blocco variabili locali: per ogni invocazione di un metodo viene allocata un'area in cui memorizzare le variabili locali durante l'intero ciclo di vita dell'invocazione. Sono memorizzati i parametri di invocazione del metodo
	- Stack degli operandi: non può superare una dimensione stabilita in anticipo. Allocato sopra il blocco delle variabili locali
	- Area dei metodi: regione di memoria in cui risiede un programma. Contiene il Program Counter

# Istruction set IJVM
- 3 istruzioni per scrittura sulla cima dello stack
- 1 istruzione per lettura sulla cima dello stack
- 3 istruzioni per manipolazione dello stack (swap, duplicazione, rimozione)
- 2 operazioni aritmetiche e 2 operazioni logiche
- 1 istruzione di incremento di una variabile
- 4 istruzioni di salto 
- 1 istruzione per specificare un indice di 16 bit 
- 2 istruzioni per chiamata dei metodi
- 1 istruzione nulla

# I registri
- Il loro compito è il controllo dell'esecuzione del programma, contenimento dei risultati temporanei e altro.
- Si suddividono in:
	- Specializzati: Program Counter, Stack Pointer e quelli visibili solo in modalità kernel
	- Di uso generale: utilizzati per memorizzare risultati temporanei delle variabili
- Il registro dei flag (Program Status Word) è un registro ibrido. Contiene vari bit necessari alla CPU e vengono impostati ad ogni ciclo dell'ALU e contengono lo stato del risultato dell'operazione più recente:
	- N: posto a 1 dopo risultato negativo.   
	- Z: posto a 1 dopo risultato uguale a 0.
	- V: posto a 1 se il risultato ha causato un overflow.
	- C: posto a 1 se il risultato ha causato un riporto oltre l’ultimo bit più significativo.
	- A: posto a 1 se si è verificato un riporto oltre il terzo bit (riporto ausiliario).
	- P: posto a 1 se il risultato è pari.