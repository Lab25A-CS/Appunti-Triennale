% permutation(L1, L2): true if L1 and L2 have the same elements
permutation([], []).
permutation([X|T], LP):-
    permutation(T, LPwithoutX),
    without(X, LP, LPwithoutX).
    
            
without(X, [X|T], T).
without(X, [Y|TY], [Y|T]):-
    without(X, TY, T).
    
/*Permutazione Prof*/

perm([],[]).

perm(L,[X|LPX]):-
    appartiene(X,L,LX),
    perm(LX,LPX).

appartiene(X,[X|L],L).
appartiene(X,[Y|L],[Y|L1]):-
    appartiene(X,L,L1).