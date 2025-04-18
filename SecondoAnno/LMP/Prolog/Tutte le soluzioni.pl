/**predicato vero se G è un goal e L è [a,b,c,c,d]*/
p(a).
p(b).
p(c).
p(c).
p(d).

/*Esploro tutto l'albero di risoluzione*/
:- dynamic appoggio/1. /*rendo il predicato appoggio dinamico*/
appoggio([]).
tutte_le_soluzioni(_):-
    p(A),
    appoggio(L),
    assert(appoggio([A|L])),
    retract(appoggio(L)),
    fail.
tutte_le_soluzioni(L):-
    appoggio(L1),
    reverse(L1,L),/*Esegue il reverse della lista L e inserisce il risultato nella lista L1*/
    retract(appoggio(L1)),
    assert(appoggio([])).

/*Setof e Bagof
 * Setof -> (schema,GOAL,L) è senza ripetizioni*
 * Esempio:
 * setof(k(A),p(A),L)
 * output L = [k(a), k(b), k(c), k(d)]
 * 
 * Bagof setssa cosa ma con ripetizioni
 * outpu : L = [k(a), k(b), k(c), k(c), k(d)]*/

p(a,1).
p(b,2).
p(c,3).
p(c,4).
p(d,5).

/*per ignorare la prima parte di p, si usa A^p(A,B) nel setof
in questo modo:
setof(k(B),A^p(A,B),L) restituisce L=[k(1),k(2),k(3),k(4),k(5)]*/

