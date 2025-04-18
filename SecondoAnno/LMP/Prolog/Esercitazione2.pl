/*Esercitazione 2*/
/*Esercizio 1*/
parente(luca, francesca).
parente(francesca, massimiliano).
parente(luca, anna).
amico(luca, matteo).
amico(matteo, orest).
amico(luca, simone).
amico(orest, thomas).
collega(luca, marco).
collega(thomas, patrick).

%catena_conoscenza(P1, P2, Cat): true se Cat è la lista di rapporti che collega P1 e P2
catena_conoscenza(P1, P2, [Rapporto]):-
    rapporto_diretto(P1, P2, Rapporto).

catena_conoscenza(P1, P2, [Rapporto|Catena]):-
    rapporto_diretto(P1, PX, Rapporto),
    catena_conoscenza(PX, P2, Catena).

rapporto_diretto(P1, P2, Rapporto):-
    parente(P1, P2),
    Rapporto = parente.
rapporto_diretto(P1, P2, Rapporto):-
    amico(P1, P2),
    Rapporto = amico.
rapporto_diretto(P1, P2, Rapporto):-
    collega(P1, P2),
    Rapporto = collega.

/*Soluzione esercizio 1 del tutor*/
conoscenza(p1,p2,primo).
conoscenza(p1,p3,amico).
conoscenza(p1,p5,collega).
conoscenza(p2,p3,primo).
conoscenza(p2,p5,primo).
conoscenza(p3,p4,collega).
conoscenza(p4,p5,amico).
 
catena_conoscenza_tutor(P1,P2,[Catena]):-
    conoscenza(P1,P2,Catena).

catena_conoscenza_tutor(P1,P2,[E|R]):-
    conoscenza(P1,P3,E),
    catena_conoscenza_tutor(P3,P2,R).

/*Esercizio 2*/
parente_migliore(luca, francesca).
parente_migliore(luca, massimiliano).
parente_migliore(massimiliano, joe).
amico_migliore(francesca, joe).
amico_migliore(francesca, franco).
collega_migliore(luca, joe).
collega_migliore(franco, marco).
collega_migliore(franco, antonio).
collega_migliore(marco, joe).

%catena_conoscenza_migliore(P1, P2, Cat): true se Cat è la lista di persone con rapporti migliori che collega P1 e P2
catena_conoscenza_migliore(P1, P2, [P2]):-
    rapporto_diretto_migliore(P1, P2).

catena_conoscenza_migliore(P1, P2, [PX|Catena]):-
    rapporto_diretto_migliore(P1, PX),
    catena_conoscenza_migliore(PX, P2, Catena).

rapporto_diretto_migliore(P1, P2):-
    parente_migliore(P1, P2).
rapporto_diretto_migliore(P1, P2):-
    amico_migliore(P1, P2).
rapporto_diretto_migliore(P1, P2):-
    collega_migliore(P1, P2).


/*Soluzione Esercizio 2 tutor*/
peso(primo,1).
peso(amico,2).
peso(collega,3).

conoscenza(p1,p2,primo).
conoscenza(p1,p3,amico).
conoscenza(p1,p5,collega).
conoscenza(p2,p3,primo).
conoscenza(p2,p5,primo).
conoscenza(p3,p4,collega).
conoscenza(p4,p5,amico).
 
catena_conoscenza_tutor(P1,P2,[Catena]):-
    conoscenza(P1,P2,Catena).

catena_conoscenza_tutor(P1,P2,[E|R]):-
    conoscenza(P1,P3,E),
    catena_conoscenza_tutor(P3,P2,R).

peso_catena([],0).
peso_catena([A|R],N):-
    peso(A,N1),
    peso_catena(R,N2),
    N is N1+N2.

listaPesiCatene([],[]).
listaPesiCatene([A|R1],[(A,B)|R2]):-
    peso_catena(A,B),
    listaPesiCatene(R1,R2).

min_catena([(L,P)],L,P).
min_catena([(L,P)|R],L,P):-
    min_catena(R,_,P1),
    P =< P1,!.
    
min_catena([_|R],L1,P1):-
    min_catena(R,L1,P1).

catena_conoscenza_da_percorrere(P1,P2,Catena):-
    setof(C,catena_conoscenza_tutor(P1,P2,C),ListaTutteCatene),
    listaPesiCatene(ListaTutteCatene,ListaPesi),
    min_catena(ListaPesi,Catena,_).
    

