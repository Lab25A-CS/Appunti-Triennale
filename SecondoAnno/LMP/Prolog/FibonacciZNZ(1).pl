fib(0,1):-!.
fib(1,1):-!.

fib(N,X):-
    !,
    Nm1 is N-1,
    Nm2 is N-2,
    fib(Nm1,Z),
    fib(Nm2,K),
    X is Z+K,
    asserta(fib(N,X):-!).