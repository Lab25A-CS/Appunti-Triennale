rettangolo(Base,0,[]).

rettangolo(Base,Altezza,[X|Rett]):-
	Altezza > 0,
	length(X,Base),
	AltezzaMeno1 is Altezza -1,
	rettangolo(Base,AltezzaMeno1,Rett).

pannello(a).
pannello(b).
pannello(c).
pannello(d).

lista_completa([]).

lista_completa([A|R]):-
	nonvar(A),
	lista_completa(R).

lista_pannelli(Lungh,Lista):-
	length(Lista,Lungh),
	lista_pannelli(Lista).

lista_pannelli([]).
lista_pannelli([X|Lista]):-
	pannello(X),
	lista_pannelli(Lista).
