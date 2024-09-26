# Ghidra

Ghidra è un tool che ci permette di de-compilare un file `.c` e di vedere nel dettaglio le chiamate di sistema, i dati e le funzioni che esso richiama

Lo usiamo per fare la parte di buffer overflow, perchè grazie a lui possiamo trovare l'indirizzo di memoria della funzione che useremo per far partire l'attacco

Per scaricarlo basta fare 

```shell
sudo apt install ghidra
```

Il tool offre molte funzionalità e vari tipi di de-compiling del codice, ma le più importanti sono i file `.got.plt`,`.got`,`.plt`

