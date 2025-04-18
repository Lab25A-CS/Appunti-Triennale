appartiene(X,[X|_]).
appartiene(X,[_|T]):-
    appartiene(X,T).

append([],L,L). %passo base%
append([HX|TX],L,[HX|TZ]):- %passo induttivo%
    append(TX,L,TZ).
/* Vogliamo eliminare i duplicati da una lista. Prendiamo ad esempio la seguente lista:

`[3,6,2,3,5,1,2,3,6]`

La lista risultante dovrebbe essere la seguente:

[1,2,3,5,6]*/
list2set([],[]).
list2set([H|T],X):-
    appartiene(H,T),
    list2set(T,X),!.
list2set([H|T],[H|X]):-
    list2set(T,X).

/*Stessa cosa di sopra ma con il sort*/
% Una lista vuota è un set vuoto
list2set_sort([],[]).
% Caso in cui H è già presente nel set
list2set_sort([H|T], SortedSet):-
    list2set_sort(T,S),
    member(H,S),
    sort(S,SortedSet),!.
% Caso in cui H non è presente nel set
list2set_sort([H|T], SortedSet):-
    list2set_sort(T,T_S),
    sort([H|T_S], SortedSet).
/* Date due liste:

    [1,2,3,5,6]
    [2,5,7]

Vorremmo avere una lista che è l'intersezione delle due, in questo caso: [2,5]*/

% Casi base, l'intersezione con l'insieme vuoto, è l'insieme vuoto
set_intersect(_,[],[]).
set_intersect([],_,[]).
% Caso in cui entrambi i set condividono H
set_intersect([H|T1], [H|T2], [H|T]):-
    set_intersect(T1,T2,T).
% Caso in cui H del primo set è minore di H del secondo set, scorri il primo
set_intersect([H1|T1], [H2|T2], IntersectedSet):-
    H1 < H2,
    set_intersect(T1, [H2|T2], IntersectedSet),!.
% Caso in cui H del secondo set è minore di H del primo set, scorri il secondo
set_intersect([H1|T1], [H2|T2], IntersectedSet):-
    H2 < H1,
    set_intersect([H1|T1], T2, IntersectedSet).