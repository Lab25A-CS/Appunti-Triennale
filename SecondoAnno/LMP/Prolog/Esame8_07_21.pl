tempo_cottura(hamburger, 2).
tempo_cottura(pollo_fritto, 3).
tempo_cottura(pollo_piastra, 1).
tempo_cottura(pesce_fritto, 2).
tempo_cottura(hamburger_vegetale, 1).
tempo_cottura(patate_fritte, 3).
tempo_cottura(alette_pollo_fritte, 3).

tempo_totale([], 0).
tempo_totale([Cibo|Cibi], Tempo) :-
    tempo_cottura(Cibo, T),
    tempo_totale(Cibi, TempoResto),
    Tempo is T + TempoResto.

fritto(pollo_fritto).
fritto(pesce_fritto).
fritto(patate_fritte).
fritto(alette_pollo_fritte).

piastra(hamburger).
piastra(pollo_piastra).
piastra(hamburger_vegetale).

tempo_frittura([], 0).
tempo_frittura([Cibo|Cibi], Tempo) :- % con una sola postazione per cucinare
    (fritto(Cibo) ->
        tempo_cottura(Cibo, T),
        tempo_frittura(Cibi, TempoResto),
        Tempo is T + TempoResto
    ;
        tempo_frittura(Cibi, Tempo)
    ).

tempo_piastra([], 0).
tempo_piastra([Cibo|Cibi], Tempo) :-
    (piastra(Cibo) -> % questa parte è un'istruzione condizionale, ovvero If-Then-else
        tempo_cottura(Cibo, T),
        tempo_piastra(Cibi, TempoResto),
        Tempo is T + TempoResto
    ;
        tempo_piastra(Cibi, Tempo)
    ). % Condizione -> Azione1; Azione2 Se condizione è vera allora si fa Azione1, altrimenti Azione2

tempo_totale_dual(Vassoio, Tempo) :- % con due postazioni per cucinare
    tempo_frittura(Vassoio, TempoFrittura),
    tempo_piastra(Vassoio, TempoPiastra),
    Tempo is max(TempoFrittura, TempoPiastra).
