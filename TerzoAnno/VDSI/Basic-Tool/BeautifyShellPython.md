# Reverse Shell

## Spawn a shell with python/python3

IL comando per spawnare una shell tty con python/python3 è : `python -c 'import pty; pty.spawn("/bin/bash")'`/`python3 -c 'import pty; pty.spawn("/bin/bash")'`

## From Simple Shell to Full TTY Interactive Shell

Step 1:
    - Premere `CTRL+Z` : Cosi facendo faremo in modo che il processo della remote shell venga messo in foreground

Step 2:
    - Scrivere il seguente comando `stty raw -echo; fg`

Step 3:
    - Scriviamo il seguente comando `export TERM=xterm-256color`, e poi premere `[Enter]`


**Nota bene** : Se non dovessero funzionare i comandi in questo modo, lanciare i seguenti comandi

Step 1:
    - Premere `CTRL+Z` 

Step 2:
    - Scrivere il seguente comando `stty raw -echo`

Step 3:
    - Scrivere il comando `reset`

Step 4:
    - Ora lanciamo `fg`

## Secondo metodo (quello funzionante)

Step 1 : 
    - Sulla shell del target fare -> `SHELL=/bin/bash script -q /dev/null`

Step 2 :
    - Poi fare `Ctrl-Z`

Step 3 : 
    - Poi `stty raw -echo && fg`

Step 4 : 
    - Quando si ritorna sulla shell fare `reset` e poi, alla domanda che ti verrà posta rispondere `xterm`


