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