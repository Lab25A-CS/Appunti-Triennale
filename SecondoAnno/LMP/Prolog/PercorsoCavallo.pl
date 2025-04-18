% Predicato per controllare se una mossa è valida ( della scacchiera e non visitata)
mossa_valida((X, Y), N, Percorso) :-
    X > 0, X =< N,
    Y > 0, Y =< N,
    \+ member((X, Y), Percorso).

% Le 8 mosse possibili del cavallo
mossa((X, Y), (NX, NY)) :- NX is X + 2, NY is Y + 1.
mossa((X, Y), (NX, NY)) :- NX is X + 2, NY is Y - 1.
mossa((X, Y), (NX, NY)) :- NX is X - 2, NY is Y + 1.
mossa((X, Y), (NX, NY)) :- NX is X - 2, NY is Y - 1.
mossa((X, Y), (NX, NY)) :- NX is X + 1, NY is Y + 2.
mossa((X, Y), (NX, NY)) :- NX is X + 1, NY is Y - 2.
mossa((X, Y), (NX, NY)) :- NX is X - 1, NY is Y + 2.
mossa((X, Y), (NX, NY)) :- NX is X - 1, NY is Y - 2.

% Predicato principale per risolvere il problema
cavallo(N, Percorso) :-
    inizia((1, 1), N, [(1, 1)], Percorso).

% Caso base: se il numero di mosse è uguale a N*N, abbiamo risolto il problema
inizia(_, N, Percorso, Percorso) :-
    length(Percorso, L),
    L =:= N * N.

% Caso ricorsivo: fai una mossa valida e continua il cammino
inizia((X, Y), N, PercorsoAttuale, Percorso) :-
    mossa((X, Y), (NX, NY)),
    mossa_valida((NX, NY), N, PercorsoAttuale),
    inizia((NX, NY), N, [(NX, NY) | PercorsoAttuale], Percorso).