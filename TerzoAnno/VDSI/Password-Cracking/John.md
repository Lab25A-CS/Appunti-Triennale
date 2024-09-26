# Cos'é John?
John the Ripper è un popolare strumento open source per il cracking delle password. È utilizzato principalmente per testare la sicurezza delle password e può eseguire attacchi di bruteforcing e basati su dizionari su vari algoritmi di hashing delle password. John the Ripper supporta un'ampia gamma di formati di hash, tra cui MD5, SHA, bcrypt, ecc.

# Come funziona?
John the Ripper utilizza diverse modalità di attacco per cercare di recuperare le password originali dagli hash. Alcune delle modalità principali includono:

- Single Crack Mode: Utilizza informazioni sugli utenti e su parole comuni per generare password candidate.
- Wordlist Mode: Utilizza un dizionario di parole per tentare di trovare una corrispondenza.
- Incremental Mode: Esegue un attacco di forza bruta provando tutte le combinazioni possibili di caratteri.

**Craccare Hash di tipo UNIX**

Abbiamo un file shadow ```/etc/shadow``` con hash delle password in formato DES
Estraiamo gli hash in file di testo(hashes.txt):
```user:$1$5f4dcc3b5aa765d61d8327deb882cf99:1000:1000::/home/user:/bin/bash```

Eseguiamo John the Ripper con i seguenti comandi:
```john hashes.txt```

Per visualizzare i risultati eseguite: 
```john --show hashes.txt```

**Craccare un Hash MD5 con un Dizionario**

Abbiamo un hash MD5 '5f4dcc3b5aa765d61d8327deb882cf99' che corrisponde a 'password'
Creiamo un file di testo contenente l'hash(hashes.txt):
```$1$5f4dcc3b5aa765d61d8327deb882cf99```

Creiamo il file di testo dizionario con parole comuni(wordlist.txt):
```
123456
password
123456789
qwerty
abc123
```

Eseguiamo John the Ripper con il dizionario:
```john --wordlist=wordlist.txt hashes.txt```

**Crack con Brute Force**

BruteForcing di un hash SHA-256
Creiamo il file di testo contenente l'hash(hashes.txt):
```$5$e3afed0047b08059d0fada10f400c1e5d96b70dcbdf36f26e01031ef9e6b86d2```

Eseguiamo John the Ripper in modalità incrementale:
```john --incremental hashes.txt```

Per visualizzare i risultati:
```john --show hashes.txt```

# Disclaimer
L'uso di John the Ripper deve essere limitato a scopi legittimi e legali, come il recupero delle proprie password dimenticate o il test di sicurezza dei propri sistemi. Utilizzare questo strumento per accedere a informazioni non autorizzate è illegale.


