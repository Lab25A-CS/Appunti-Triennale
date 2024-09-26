# GoBuster

Tool usato per effettuare l'enumerazione dei siti web.

Il tool ci permette di trovare tutte le sottodirectory/risorse che si trovano su un web server.

Per lanciare il comando bisogna fare

`gobuster OPTIONS`

## Enumerazione directory

Si usa il comando in questo modo

`gobuster dir -u http://<target_ip> -w <wordlist>`

Se si vogliono escludere gli status code possiamo usare il flag `-s` e darglik tutti gli status code che non vogliamo, oppure se si vuole escludere la lunghezza dobbiamo usare il flag `--exclude-length <int>`

E tante altre cose

## Enumerazione virtual host

Come le directory, con gobuster possiamo enumerare i virtual host

Per enumerare i virtual host, basta modificare l'opzione `dir` con `vhost`, e alla fine del comando scrivere `--append-domain`

## Enumerazioe (DAVIDE)

Il tool più usato è GoBuster, che punta ad un url o ad una porta e invia richieste http get al sito utilizzando le wordlist. Se l'url da risposte positive (200) esistono sottocartelle in quel sito, e gobuster le mostra. Da usare in questo modo:

gobuster dir -u https://buffered.io -w ~/wordlists/shortlist.txt

Dove:
-u = Richiesta dell'url
-w = Specifica la wordlist

Altre flag utili:
-v = Aggiunge verbosità alla scansione
--retry = Quando si trova in "request timeout" riprova la scansione

Altro esempio comune:

gobuster dir -u https://mysite.com/path/to/folder -c 'session=123456' -t 50 -w common-files.txt -x .php,.html
