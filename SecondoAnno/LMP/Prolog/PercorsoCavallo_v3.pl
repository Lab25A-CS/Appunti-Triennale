% Con scacchiera 8x8

%% Movimento del cavallo
%mossa(X/Y, X1/Y1) :-
%    member((DX, DY), [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]),
%    X1 is X + DX, Y1 is Y + DY,
%    X1 >= 1, X1 =< 8, Y1 >= 1, Y1 =< 8.
%
%% Predicato per contare il numero di mosse disponibili da una posizione
%conteggio_mosse(X/Y, Count) :-
%    findall(X1/Y1, (mossa(X/Y, X1/Y1), \+ member(X1/Y1, [(X/Y)])), Moves),
%    length(Moves, Count).
%
%% Trova tutte le mosse possibili, ordinate in base al numero di mosse successive possibili (Euristica di Warnsdorff)
%mosse_possibili_ordinate(X/Y, Visitati, MosseOrdinate) :-
%    findall(Count-(X1/Y1),
%            (mossa(X/Y, X1/Y1),
%             \+ member(X1/Y1, Visitati),
%             conteggio_mosse(X1/Y1, Count)),
%            Mosse),
%    keysort(Mosse, Ordinata),
%    pairs_values(Ordinata, MosseOrdinate).
%
%% Predicato principale per trovare il percorso del cavallo
%tour_cavallo(X/Y, Percorso) :-
%    tour_cavallo(X/Y, [(X/Y)], Percorso).
%
%% Caso base: il percorso è completo quando si sono visitate 64 caselle
%tour_cavallo(_, Percorso, Percorso) :-
%    length(Percorso, 64).
%
%% Ricorsione per continuare il percorso usando l'euristica di Warnsdorff
%tour_cavallo(X/Y, Visitati, Percorso) :-
%    mosse_possibili_ordinate(X/Y, Visitati, MosseOrdinate),
%    member(NextMove, MosseOrdinate),
%    tour_cavallo(NextMove, [NextMove|Visitati], Percorso).
%
%% Query di esempio:
%% ?- tour_cavallo(1/1, Percorso).

% --- Versione con dimensione variabile

% Movimento del cavallo su una scacchiera di dimensioni arbitrarie
mossa(Larghezza, Altezza, X/Y, X1/Y1) :-
    member((DX, DY), [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]),
    X1 is X + DX, Y1 is Y + DY,
    X1 >= 1, X1 =< Larghezza, Y1 >= 1, Y1 =< Altezza.

% Predicato per contare il numero di mosse disponibili da una posizione
conteggio_mosse(Larghezza, Altezza, X/Y, Visitati, Count) :-
    findall(X1/Y1, (mossa(Larghezza, Altezza, X/Y, X1/Y1), \+ member(X1/Y1, Visitati)), Moves),
    length(Moves, Count).

% Trova tutte le mosse possibili, ordinate in base al numero di mosse successive possibili (Euristica di Warnsdorff)
mosse_possibili_ordinate(Larghezza, Altezza, X/Y, Visitati, MosseOrdinate) :-
    findall(Count-(X1/Y1),
            (mossa(Larghezza, Altezza, X/Y, X1/Y1),
             \+ member(X1/Y1, Visitati),
             conteggio_mosse(Larghezza, Altezza, X1/Y1, Visitati, Count)),
            Mosse),
    keysort(Mosse, Ordinata),
    pairs_values(Ordinata, MosseOrdinate).

% Predicato principale per trovare il percorso del cavallo
tour_cavallo(Larghezza, Altezza, X/Y, Percorso) :-
    CaselleTotali is Larghezza * Altezza,
    tour_cavallo(Larghezza, Altezza, X/Y, [(X/Y)], Percorso, CaselleTotali),
    length(Percorso,TotCaselle),
    write('Numero caselle visitate: '), write(TotCaselle),nl.

% Caso base: il percorso è completo quando si sono visitate tutte le caselle
tour_cavallo(_, _, _, Percorso, Percorso, CaselleTotali) :-
    length(Percorso, CaselleTotali).

% Ricorsione per continuare il percorso usando l'euristica di Warnsdorff
tour_cavallo(Larghezza, Altezza, X/Y, Visitati, Percorso, CaselleTotali) :-
    mosse_possibili_ordinate(Larghezza, Altezza, X/Y, Visitati, MosseOrdinate),
    member(NextMove, MosseOrdinate),
    tour_cavallo(Larghezza, Altezza, NextMove, [NextMove|Visitati], Percorso, CaselleTotali).

% Query di esempio:
% ?- tour_cavallo(8, 8, 1/1, Percorso).  % Scacchiera 8x8, partenza da (1,1)
% ?- tour_cavallo(5, 5, 1/1, Percorso).  % Scacchiera 5x5, partenza da (1,1)
