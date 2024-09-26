# Basic Enumeration Tool

## Nmap

Nmap è il tool che server per fare port scanning sul target.

L'attacco ha vari tipi e modalità, ma quello più classico e semplice è 

`sudo nmap -sC -sV -Pn -p- <target-ip>`

cosa fanno i flag?

- sC : Equivalente a --script=default, usa lo script di scanning di default
- sV : Stampa le informazioni relative alla versione del servizio sulla porta
- Pn : Tratta tutti gli host come stato online -- skip host discovery
- -p- : Fa lo scan su tutte le porte del target, si può anche impostare cosi -p5-10, e in questo modo esegue lo scan solo sulle porte dalla 5 alla 10

I vari tipi di attacco nmap sono : 
- sS/sT/sA/sW/sM: TCP SYN/Connect()/ACK/Window/Maimon scans
- sU: UDP Scan

Per qualunque informazione lanciare il comando `man nmap`

## Esempio di Attacco

`nmap -A -T4 scanme.nmap.org`

           Nmap scan report for scanme.nmap.org (74.207.244.221)
           Host is up (0.029s latency).
           rDNS record for 74.207.244.221: li86-221.members.linode.com
           Not shown: 995 closed ports
           PORT     STATE    SERVICE     VERSION
           22/tcp   open     ssh         OpenSSH 5.3p1 Debian 3ubuntu7 (protocol 2.0)
           | ssh-hostkey: 1024 8d:60:f1:7c:ca:b7:3d:0a:d6:67:54:9d:69:d9:b9:dd (DSA)
           |_2048 79:f8:09:ac:d4:e2:32:42:10:49:d3:bd:20:82:85:ec (RSA)
           80/tcp   open     http        Apache httpd 2.2.14 ((Ubuntu))
           |_http-title: Go ahead and ScanMe!
           646/tcp  filtered ldp
           1720/tcp filtered H.323/Q.931
           9929/tcp open     nping-echo  Nping echo
           Device type: general purpose
           Running: Linux 2.6.X
           OS CPE: cpe:/o:linux:linux_kernel:2.6.39
           OS details: Linux 2.6.39
           Network Distance: 11 hops
           Service Info: OS: Linux; CPE: cpe:/o:linux:kernel

           TRACEROUTE (using port 53/tcp)
           HOP RTT      ADDRESS
           [Cut first 10 hops for brevity]
           11  17.65 ms li86-221.members.linode.com (74.207.244.221)

           Nmap done: 1 IP address (1 host up) scanned in 14.40 seconds


