:- dynamic mossa/1.

mossa([]).

controllo([X1,Y1],[X2,Y2]):-
    \+mossa([X2,Y2]),
    1 is abs(X1-X2),
    2 is abs(Y1-Y2),
    asserta(mossa([X2,Y2])).

controllo([X1,Y1],[X2,Y2]):-
    \+mossa([X2,Y2]),
    2 is abs(X1-X2),
    1 is abs(Y1-Y2),
    asserta(mossa([X2,Y2])).

controlloMosse([X1,Y1],[X2,Y2]):-
    controllo([X1,Y1],[X2,Y2]).

controlloMosse([[X1,Y1],[X2,Y2]]):-
    controllo([X1,Y1],[X2,Y2]),!.

controlloMosse([[X1,Y1],[X2,Y2]|[T]]):-
    controllo([X1,Y1],[X2,Y2]),
    controlloMosse([X2,Y2],T).

soluzione([[X1,Y1]|T]):-
    asserta(mossa([X1,Y1])),
    controlloMosse([[X1,Y1]|T]),
    listing(mossa),
    retractall(mossa(_)).
   
soluzione([[_,_]|_]):-
    retractall(mossa(_)),
    fail.