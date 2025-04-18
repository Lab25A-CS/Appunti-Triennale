:- dynamic ingredienti_in_dispensa/1.
:- dynamic ingredienti_in_frigorifero/1.

% Definizione degli ingredienti disponibili in dispensa e frigorifero con quantità
ingredienti_in_dispensa([carne-500, pasta-300, pomodoro-200, cipolla-100, aglio-50, olio-500, sale-200, pepe-50]).
ingredienti_in_frigorifero([pollo-600, verdure-300, latte-500, uova-12, formaggio-200]).

% Definizione dei piatti con ingredienti e tempo di preparazione
piatto(cotoletta, [carne-200, sale-5, pepe-2], 15).
piatto(spaghetti, [pasta-100, pomodoro-100, aglio-5, olio-10, sale-5, pepe-2], 30).
piatto(omelette, [uova-3, latte-50, sale-5, pepe-2], 50).

% Predicato per suggerire un piatto per oggi
piatto_per_oggi(TempoMax, NumPersone, NomePiatto, IngredientiConQuantita) :-
    piatto(NomePiatto, IngredientiNecessari, TempoPreparazione),
    TempoPreparazione =< TempoMax,
    ingredienti_per_persone(IngredientiNecessari, NumPersone, IngredientiConQuantita),
    ingredienti_disponibili(IngredientiConQuantita),
    ho_preparato(NomePiatto, IngredientiConQuantita),
    write("Ho preparato: "), write(NomePiatto), nl.

% Predicato per calcolare la quantità totale degli ingredienti in base al numero di persone
ingredienti_per_persone([], _, []).
ingredienti_per_persone([Ingrediente-Quantita|Altri], NumPersone, [Ingrediente-QuantitaTotale|AltriRisultato]) :-
    QuantitaTotale is Quantita * NumPersone,
    ingredienti_per_persone(Altri, NumPersone, AltriRisultato).

% Predicato per verificare se gli ingredienti necessari sono disponibili
ingredienti_disponibili([]).
ingredienti_disponibili([Ingrediente-QuantitaRichiesta|Altri]) :-
    (ingredienti_in_dispensa(Dispensa), member(Ingrediente-QuantitaDisponibile, Dispensa), QuantitaDisponibile >= QuantitaRichiesta;
     ingredienti_in_frigorifero(Frigorifero), member(Ingrediente-QuantitaDisponibile, Frigorifero), QuantitaDisponibile >= QuantitaRichiesta),
    ingredienti_disponibili(Altri).

% Predicato per rimuovere gli ingredienti utilizzati dalla dispensa e dal frigorifero
ho_preparato(_, []).
ho_preparato(_, [Ingrediente-Quantita|Altri]) :-
    (ingredienti_in_dispensa(Dispensa), select(Ingrediente-QuantitaDisponibile, Dispensa, RestoDispensa), 
     QuantitaRimanente is QuantitaDisponibile - Quantita,
     (QuantitaRimanente > 0 -> NuovaDispensa = [Ingrediente-QuantitaRimanente|RestoDispensa] ; NuovaDispensa = RestoDispensa),
     retract(ingredienti_in_dispensa(_)), assertz(ingredienti_in_dispensa(NuovaDispensa))
    ;
    ingredienti_in_frigorifero(Frigorifero), select(Ingrediente-QuantitaDisponibile, Frigorifero, RestoFrigo), 
    QuantitaRimanente is QuantitaDisponibile - Quantita,
    (QuantitaRimanente > 0 -> NuovoFrigo = [Ingrediente-QuantitaRimanente|RestoFrigo] ; NuovoFrigo = RestoFrigo),
    retract(ingredienti_in_frigorifero(_)), assertz(ingredienti_in_frigorifero(NuovoFrigo))
    ),
    ho_preparato(_, Altri).

