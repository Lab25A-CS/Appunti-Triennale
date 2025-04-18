/*Versione base 3+4+5 = +(A,B)., output A=3+4,B=5
 * 
 * versione nostra
 * op(500,xfy,+).
	3+4+5 = +(A,B).
	A = 3,
	B = 4+5.*/
/*con op si definisce un'operatore, in questo modo:
 * op(Precedenza, Tipo, Nome), vedi help(op)*/

/*Esercizio, definire operatori che permettano di interpretare la frase:
 *  "mario mangia mela con coltello"
 * e
 * "mario mangia pera"
 * "mario mangia zucchina"
 * "mario mangia pane"*/

/*Gli operatori da definire sono "mangia,con"*/

/*la domanda a cui rispondere è Chi mangia Cosa, e vogliamo mangia(mario,pera)*/

/*Soluzione:
 * op(400,xfx,mangia).
 * op(300,xfy,di)*/


:- op(400,xfx,[mangia,porta]).
:- op(300,yfx,di).
/*:- op(400,xfy,porta).*/

mario mangia mela.
maria mangia zucchina.
mario mangia zucchina.
mario mangia panino di forno.
mario mangia panino di forno di marino.
mario mangia pera.

mario porta borsa di pelle.
mario porta borsa di pelle di leopardo.
mario porta borsa di pelle di nonna.

/*Le query sono del tipo "mario porta Cosa di Chi","mario mangia Cosa", etc..*/
