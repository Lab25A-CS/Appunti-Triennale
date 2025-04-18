appartiene(X,[X|_]).
appartiene(X,[_|T]):-
    appartiene(X,T).

append([],L,L). %passo base%
append([HX|TX],L,[HX|TZ]):- %passo induttivo%
    append(TX,L,TZ).

reverse([],L,L). %passo base%
reverse([HX|TX],X,RL):- %passo induttivo%
    reverse(TX,HX,RL),
    append([],X,X).

reverse_prof([],[]).
reverse_prof([HX|TX],R):-
    append(TR,[HX],R),
    reverse_prof(TX,TR).

perm([],P).
perm([HX|TX],P):-
    appartiene(HX,P),
    perm(TX,P).
    