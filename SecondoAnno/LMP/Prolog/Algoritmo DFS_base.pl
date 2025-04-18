edge(a,b).
edge(a,c).
edge(b,d).
edge(b,k).
edge(c,e).
edge(c,d).
edge(c,n).
edge(e,f).
edge(f,f).
edge(f,d).
edge(e,n).
edge(n,a).


path(X,Y,[X,Y]):-
    edge(X,Y).

path(X,Y,[X|P_Z_Y]):-
    edge(X,Z),
    path(Z,Y,P_Z_Y).
