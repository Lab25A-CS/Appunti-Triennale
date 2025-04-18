/*Esercizio Outlook professore*/

/*Si vuole costruire un aiuto per fare orario settimanale delle lezioni.

Si hanno a disposizione 2 aule e si vogliono disporre 10 corsi ciascuno con 4 ore settimanali.

 

Vincoli:

Un docente ha più corsi.

I docenti posso esprimere “preferenza” fascia oraria.

I corsi dello stesso anno non possono sovrapporsi.

Deve essere data una fascia libera per il pranzo.

Se ve ne vengono in mente altri….*/

/*Docente insegna Corso relazione 1:N*/

/*docente(fabio,zanzotto,1,[prolog,analisi]).
corsi(prolog,4).
corsi(python,4).
corsi(analisi,4).
corsi(matematica_discreta,4).*/

/*L è una lista composta da prima gialli, po verdi e poi rossi*/
frutto(melaSmith,1,verde).
frutto(melaSmith,2,verde).
frutto(melaFuji,2,rossa).
frutto(banana,2,gialla).
frutto(melone,2,gialla).

memberOur(A,[A|L],L).%vero se A è il primo ele,ento e il restante è la coda della lista
memberOur(A,[B|L],[B|L1]):-%vero se L1 è la lista restante ì, privata di A, con in testa l elemento B
    memberOur(A,L,L1).

collocati(L):-
    length(L,7),
    bagof((F,C),B^frutto(F,B,C),LFP),
    collocatiWorker(L,LFP).

collocatiWorker([],[]).
collocatiWorker([(E,COLORE)|L],LFP):-
    memberOur((E,COLORE),LFP,LFPmenoFruttoAttuale),
    collocatiWorker(L,LFPmenoFruttoAttuale),
    listaColori(L,LC),
    vincoliRispettati([COLORE|LC]).

collocatiWorker([(empty,nc)|L],LFP):- /*nc sta per nessun colore*/
    collocatiWorker(L,LFP),
    listaColori(L,LC),
    vincoliRispettati(LC).

listaColori([],[]).
listaColori([(_,C)|RL],[C|RC]):-
    %\+(C = nc),
    listaColori(RL,RC).

listaColori([(_,nc)|RL],RC):- /*tolgo gli elementi nc dalla lista*/
    !,
    listaColori(RL,RC).

precede(nc,_).
precede(_,nc).
precede(verde,rosso).
precede(giallo,rosso).
precede(giallo,verde).
precede(A,A).

vincoliRispettati([]).
vincoliRispettati([_]).
vincoliRispettati([A,B|L]):-
	precede(A,B),
    vincoliRispettati([B|L]).


