/*assert -> asserisci = immetti*/
/*retrat -> retrattare = togliere*/
/*=.. -> (   )=.. [   ] predicato univ, consente di spacchettare o impacchettare */
/*Esempio : L=..[k,1,2,3] diventa L=k(1,2,3)*/

/*Esempio di assert
 * assert(p(a,b)),
listing(p)
genera questo output
:- dynamic p/2.

p(a, b).*/

/*Esempio di retract
 * assert(p(a,b)).
true.
assert(p(a,a)).
true.
assert(p(a,z)).
true.

listing(p)
:- dynamic p/2.

p(a, b).
p(a, a).
p(a, z).

true.

retractall(p(a,B)).
true.

listing(p).
:- dynamic p/2.

true. 
 * */
/*implementazione di retractAll usando il retract*/
ritrattaTutto(P):-
    retract(P),
    fail.
ritrattaTutto(_).