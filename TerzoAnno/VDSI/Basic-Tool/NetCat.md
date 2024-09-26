# NetCat

Il tool netcat viene usato per connettersi in reverse shell con il target

Il comando per fare ciò è 
`nc -lvnp <PORTA>`

Con netcat possiamo anche inviare e ricevere file dal target 

Per mandare file fare : 

`nc -w 3 <TARGET-IP> <PORT> < <FILENAME>`

Per ricevere :

`nc -l -p <PORT> > <FILENAME>`

Ovviamente port e filename devono essere uguali

