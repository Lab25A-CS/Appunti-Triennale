# Binary Exploitation and Buffer Overflow

Il buffer overflow è una tecnica che ci permette di andare ad effettuare degli exploit su dei file binari, in modo da prendere i permessi di root della macchina

Prima di vedere i comandi dobbiamo parlare dei bit `NX` e `ASRL`, parlare della `libc`

## Bit NX

NX = No eXecute 

Il bit NX è un bit che, se abilitato, ci dice che non possiamo eseguire i nosti `shellcode` tramite lo stack, e per bypassarlo dobbiamo usare un attacco di tipo `ret2libc` 

## PIE

Se PIE è disabilitato, significa che il nostro binario inizierà sempre dall'indirizzo 0x400000 e non è affetto dal bit ASRL

## Bit ASRL

ASRL = Address Space Layout Randomisation

Il bit ASRL è una tecnica di sicurezza progettata per impedire lo sfruttamento delle vulnerabilità di corruzione della memoria.

Se il bit ASRL è attivo, l'indirizzo di memoria del file `libc` cambiarà ad ogni esecuzione del codice.
Questo implica una difficoltà maggiore quando si crea l'exploit, ma anche questo è raggirabile

Per vedere se il bit ASRL è attivo possiamo lanciare il comando

```shell 
cat /proc/sys/kernel/randomize_va_space 
```

Se il risultato è 2, significa che ASRL è attivo, se il risultato è 1 significa che non è attivo

Per vedere se questi bit sono attivi sul binario, lanciare il comando `checksec <binario>`

Per un chiarimento migliore rimando a queste guide :
- Parte 1 -> [GUIDA](https://valsamaras.medium.com/introduction-to-x64-linux-binary-exploitation-part-1-14ad4a27aeef) Basic Buffer Overflow
- Parte 2 -> [GUIDA](https://valsamaras.medium.com/introduction-to-x64-binary-exploitation-part-2-return-into-libc-c325017f465) Attacco di tipo `ret2libc`
- Parte 3 -> [GUIDA](https://valsamaras.medium.com/introduction-to-x64-linux-binary-exploitation-part-3-rop-chains-3cdcf17e8826) Protezione NX attiva, creazione di `ROP Chain`
- Parte 4 -> [GUIDA](https://valsamaras.medium.com/introduction-to-x64-linux-binary-exploitation-part-4-stack-canaries-e9b6dd2c3127) Spiega gli stack canaries
- Parte 5 -> [GUIDA](https://valsamaras.medium.com/introduction-to-x64-linux-binary-exploitation-part-5-aslr-394d0dc8e4fb) Spiega ASRL

### Tutorial

Vedere questa macchina per spiegazioni dettagliate e un tutorial su come creare l'expploit [Macchina](https://tryhackme.com/r/room/ret2libc)

### GUIDA

Questo sito offre un riassunto molto dettagliato su tutta la parte di BinaryExploitation e BufferOverlfow.

Il sito è il seguente : [Sito](https://ctf101.org/binary-exploitation/overview/)

### Spiegazione e dettagli 

In questo sito possiamo trovare una spiegazione molto dettagliata su tutti gli argomenti che formano il Binary Exploitation 

Il sito è il seguente -> [Spiegazione](https://ir0nstone.gitbook.io/notes/types/stack)
