# Cos'é HashCat
Hashcat è uno strumento di recupero password avanzato che sfrutta la potenza di calcolo delle GPU per eseguire attacchi di: bruteforcing, combination attack, mask attack e dizionari su hash delle password. Supporta una vasta gamma di algoritmi di hashing ed è noto per la sua velocità ed efficienza.

## Come funziona?

Hashcat utilizza diverse modalità di attacco per cercare di recuperare le password originali dagli hash. Alcune delle modalità principali includono:

- Dizionario (Dictionary Attack): Utilizza un elenco di parole (dizionario) come input per tentare di trovare la corrispondenza.
- Forza Bruta (Brute-force Attack): Prova tutte le possibili combinazioni di caratteri fino a trovare la password corretta.
- Combinazione (Combination Attack): Combina due dizionari insieme.
- Maschera (Mask Attack): Simile alla forza bruta, ma limitata a un set specifico di caratteri e una lunghezza definita.

## Esempi pratici

**Crack di un hash MD5 con dizionario**

Creiamo un file contente l'hash (hash.txt): 

```5f4dcc3b5aa765d61d8327deb882cf99```

Creiamo un file (dizionario.txt) con parole comuni:

```
123456
password
123456789
qwerty
abc123
```
Eseguiamo hashcat usando il file dizionario:

```hashcat -m 0 -a 0 -o found.txt hashes.txt dictionary.txt```

- -m 0: Specifica l'algoritmo di hash (0 per MD5).
- -a 0: Specifica l'attacco di tipo dizionario.
- -o found.txt: File di output per le password trovate.

**Crack di un hash SHA256**

Creiamo un file contenente l'hash (hash.txt):

```e3afed0047b08059d0fada10f400c1e5d96b70dcbdf36f26e01031ef9e6b86d2```

Eseguiamo hashcat con bruteforce:

```hashcat -m 1400 -a 3 hashes.txt ?a?a?a?a?a?a?a?a```

- -m 1400: Specifica l'algoritmo di hash (1400 per SHA256).
- -a 3: Specifica l'attacco di forza bruta.
- ?a?a?a?a?a?a?a?a: Prova tutte le combinazioni di 8 caratteri (a-z, A-Z, 0-9 e simboli).

# Disclaimer

L'uso di hashcat per craccare password deve essere fatto solo per scopi legittimi e legali, come il recupero delle proprie password dimenticate. Utilizzare questo strumento per accedere a informazioni non autorizzate è illegale.
