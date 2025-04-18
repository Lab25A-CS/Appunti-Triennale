% Grammatica DCG per generare fatti mangia/2

% Regole della grammatica
frase_mangia(mangia(X,Y)) --> articolo, soggetto(X), [si, nutre, di], oggetto(Y),{ assertz(mangia(X, Y)) }.
frase_mangia(mangia(X,Y)) --> articolo, soggetto(X), [mangia,la], oggetto(Y),{ assertz(mangia(X, Y)) }.

% Articoli
articolo --> [il].
articolo --> [la].

% Soggetti (animali o esseri viventi che si nutrono)
soggetto(cavallo) --> [cavallo].
soggetto(gatto) --> [gatto].
soggetto(pesce) --> [pesce].
soggetto(cervo) --> [cervo].
soggetto(topo) --> [topo].
soggetto(ragno) --> [ragno].
soggetto(microrganismo) --> [microrganismo].

% Oggetti (ciò di cui si nutrono)
oggetto(biada) --> [biada].
oggetto(pesce) --> [pesce].
oggetto(microrganismo) --> [microrganismo].
oggetto(plankton) --> [plankton].
oggetto(rosmarino) --> [rosmarino].
oggetto(erba) --> [erba].
oggetto(topo) --> [topo].

% Esempio di traduzione
% ?- frase_mangia(Fatto, [il, cavallo, si, nutre, di, biada], []).
% Fatto = mangia(cavallo, biada).

contaminato(plankton).
contaminato(biada).

% Fattore di attenuazione
fattore_attenuazione(0.87).

% Regola per calcolare la contaminazione a distanza e il livello di contaminazione
contaminato_a_distanza(X, Distanza, LivelloContaminazione) :-
    contaminato(X),
    Distanza is 0,
    LivelloContaminazione is 1. % La specie contaminata ha livello 1
contaminato_a_distanza(X, Distanza, LivelloContaminazione) :-
    mangia(X, Y),
    contaminato_a_distanza(Y, Distanza1, LivelloContaminazione1),
    Distanza is Distanza1 + 1,
    fattore_attenuazione(F),
    LivelloContaminazione is LivelloContaminazione1 * F.

% Query di esempio
%?- contaminato_a_distanza(gatto, Distanza, LivelloContaminazione).
