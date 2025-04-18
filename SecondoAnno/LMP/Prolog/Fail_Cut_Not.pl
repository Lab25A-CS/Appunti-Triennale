/*introduzione del predicato fail e del cut*/

/*fail - questo predicato fallisce sempre*/

/*il fail permette l'esplorazione dell'intero albero di ricerca*/

/*il cut è il taglio dello spazio di ricerca*/
/*tutto quello che sta prima del cut non può essere reistanziato*/
prova(X):-
    riprova(X),!,
    write(X),nl, /*write stampa, nl va a capo*/
    fail.
prova(_).    
/*prova2(X,B,C):-
    riprova(X,B),!, ! è il cut
    riprova2(X,C).

riprova(d,1).
riprova(d,2).
riprova(e,3).
riprova(c,4).
riprova(f,5).
riprova(g,6).
riprova2(d,1).
riprova2(e,2).
riprova2(d,3).*/

riprova(f).
riprova(e).
riprova(d).
riprova(c).
riprova(g).

/*predicato not_member -> true se X non appartiene a L, false altrimenti*/
not_member(X,[X|_]):-
    !,
    fail.
not_member(X,[_|M]):-
    !,
    not_member(X,M).
not_member(_,_).

vero(P):-
    P.
/*non_vero -> true se il predicato P è falso, false altrimenti (questo è il not)*/
non_vero(P):-
    P,!,fail.
non_vero(_).

/*il not esist ein Prolog ed è \+P*/
\+P.




