% Definizione delle vocali
vocale('a').
vocale('e').
vocale('i').
vocale('o').
vocale('u').
vocale('A').
vocale('E').
vocale('I').
vocale('O').
vocale('U').

% Conta il numero di vocali in una lista
nV([], 0).
nV([E|T], M) :-
    vocale(E), !, % Se è una vocale, incrementa il conteggio
    nV(T, N),
    M is N + 1.
nV([_|T], M) :- 
    nV(T, M).

% Conta il numero di consonanti in una lista
nC([], 0).
nC([E|T], M) :-
    \+ vocale(E), char_type(E, alpha), !, % Se è una consonante (lettera non vocale), incrementa il conteggio
    nC(T, N),
    M is N + 1.
nC([_|T], M) :-
    nC(T, M).

% Predicato che controlla se il numero di vocali è uguale al numero di consonanti
calcolo(A, B) :-
    A = B, !,
    write("Giornata Fortunata").
calcolo(A, B) :-
    \+ A = B,
    write("Giornata Sfortunata").

% Predicato principale che prende un messaggio e decide se la giornata è fortunata
giornata(Segno) :-
    %string_chars(Messaggio, Segno), % Converte il messaggio in lista di caratteri
    nV(Segno, A),                   % Conta il numero di vocali
    nC(Segno, B),                   % Conta il numero di consonanti
    calcolo(A, B).                  % Verifica se la giornata è fortunata o sfortunata

