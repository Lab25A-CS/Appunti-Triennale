Problema delle otto regine corretto

codice 

```prolog
genera(N,Allocazione):- 
    length(Allocazione,N),
	valori_ammessi(N,ListaValori),
	funzione(Allocazione,ListaValori).

valori_ammessi(N,[N|R]):- 
    N>0,
	M is N-1,
	valori_ammessi(M,R).

valori_ammessi(0,[]).

funzione([A|R],Cod):-
    member(A,Cod),
 	funzione(R,Cod).
funzione([],Cod).

safe([]).

safe([Q|Qs]):- 
    safe(Qs),
	nonattacca(Q,Qs).

nonattacca(X,Xs):- 
    natt(X,1,Xs).

natt(X,_,[]).

natt(X,Offset,[Y|R]):- 
    X =\= Y+Offset, X =\= Y, X =\= Y-Offset,
	N1 is Offset+1, natt(X,N1,R).

regine(N,Allocazione) :- 
    genera(N,Allocazione),
	safe(Allocazione).
```

Spiegazione [qui](http://users.dimi.uniud.it/~agostino.dovier/DID/lnc.pdf#page=97)

Codice riscitto meglio

```prolog
regine(N,Soluzioni):-
	genera(N,Soluzioni),
    safe(Soluzioni).

genera(N,Regine):-
    length(Regine,N),
    genera_valori(N,RegineGenerate),
    sposta_regine(Regine,RegineGenerate).

genera_valori(0,[]).

genera_valori(N,[N|R]):-
	N>0,
    M is N-1,
    genera_valori(M,R).

sposta_regine([],_).

sposta_regine([R1|RestoReg],ListaRegine):-
    member(R1,ListaRegine), % la member fatta cosi inserisce R1 in ListaRegine
    sposta_regine(RestoReg,ListaRegine).

safe([]).

safe([Regina|RegineRimanenti]):-
    safe(RegineRimanenti),
    no_atk(Regina,RegineRimanenti).

no_atk(Regina,RegRim):-
    nessun_attacco(Regina,1,RegRim). % 1= offset per trovatre la permutazione corretta, ovvero quella che divide i valori di alemno 2 posizioni (es: 2,4,1,3)

nessun_attacco(_,_,[]).

nessun_attacco(X,Offset,[R|T]):-
    X =\= R+Offset, % per diag dx
    X =\= R,
    X =\= R-Offset, % per diag sx
    OffsetPiu1 is Offset+1,
    nessun_attacco(X,OffsetPiu1,T).
```
