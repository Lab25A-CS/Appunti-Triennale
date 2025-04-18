/*torri di hanoi*
torri([[a,b,c],[],[]]).
torri([[b,c],[],[a]]).
torri([[c],[b],[a]]).
torri([[c],[a,b],[]]).
torri([[],[a,b],[c]]).
torri([[a],[b],[c]]).
torri([[a],[],[b,c]]).
torri([[],[],[a,b,c]]).*/


valida(L):-ordinata(L).
ordinata([]).
ordinata([_]).
ordinata([X1,X2|L]):-
    X1<X2,
    ordinata([X2|L]).

edge([[H1|T1], L2, L3],
     [T1, [H1|L2], L3 ]):-
    valida([H1|L2]).
edge([[H1|T1], L2, L3],
     [T1, L2, [H1|L3] ]):-
    valida([H1|L3]).
edge([L1, [H2|T2], L3],
     [[H2|L1], T2, L3 ]):-
    valida([H2|L1]).
edge([L1, [H2|T2], L3],
     [L1, T2, [H2|L3] ]):-
    valida([H2|L3]).
edge([L1, L2, [H3|T3]],
     [[H3|L1], L2, T3 ]):-
    valida([H3|L1]).
edge([L1, L2, [H3|T3]],
     [L1, [H3|L2], T3 ]):-
    valida([H3|L2]).

path(A,B,[A,B]):-
    edge(A,B).
path(A,B,[A|P1]):-
    path(X,B,P1),
    edge(A,X).



