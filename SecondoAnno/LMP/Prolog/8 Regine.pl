% Predicato principale per risolvere il problema delle 8 regine
eight_queens(Board) :-
    % Inizializza una lista di variabili [1,2,3,4,5,6,7,8]
    Board = [1,2,3,4,5,6,7,8],
    % Permuta Board in tutte le possibili disposizioni
    permutation(Board, Perm),
    % Verifica se Perm è una soluzione valida
    valid_solution(Perm).

% Predicato per verificare se una disposizione delle regine è valida
valid_solution(Board) :-
    % Verifica la disposizione delle regine su ogni colonna
    valid_solution(Board, 1, []).

% Caso base: tutte le colonne sono state verificate
valid_solution([], _, _).

% Predicato ricorsivo per verificare la validità delle regine
valid_solution([Y|Ys], X, Xs) :-
    % Verifica che la regina in riga X e colonna Y non minacci le altre
    no_attack(X, Y, Xs),
    % Procede con le colonne successive
    X1 is X + 1,
    valid_solution(Ys, X1, [Y|Xs]).

% Predicato per verificare che la regina in riga X e colonna Y non minacci le altre regine
no_attack(_, _, []).
no_attack(X, Y, [Y1|Ys]) :-
    % Verifica che non ci siano attacchi in diagonale
    Y1 - Y =\= X - 1,
    Y - Y1 =\= X - 1,
    % Verifica che non ci siano attacchi sulla stessa riga
    no_attack(X, Y, Ys).

% Predicato per stampare una soluzione della scacchiera
print_board([]).
print_board([Y|Ys]) :-
    print_row(Y),
    print_board(Ys).

% Predicato per stampare una riga della scacchiera con la posizione della regina
print_row(Y) :-
    N is 8,
    print_row(Y, 1, N).

print_row(Y, Col, N) :-
    ( Col =:= Y -> write(' Q ') ; write(' . ') ),
    ( Col =:= N -> nl ; (write(' | '), Col1 is Col + 1, print_row(Y, Col1, N)) ).

% Esempio di utilizzo:
% ?- eight_queens(Board), print_board(Board).
