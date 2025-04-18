mattonella(5, 5).
mattonella(10, 10).
mattonella(10, 20).
mattonella(5, 10).

pavimentazione_superficie(Lunghezza, Larghezza, Pavimentazione, NumeroMattonelleUtilizzate) :-
    pavimenta(Lunghezza, Larghezza, [], Pavimentazione, 0, NumeroMattonelleUtilizzate).

pavimenta(0, 0, Pavimentazione, Pavimentazione, NumeroMattonelleUtilizzate, NumeroMattonelleUtilizzate).
pavimenta(Lunghezza, Larghezza, Parziale, Pavimentazione, MattonelleParziali, NumeroMattonelleUtilizzate) :-
    mattonella(W, H),
    W =< Lunghezza,
    H =< Larghezza,
    NuovaLunghezza is Lunghezza - W,
    NuovaLarghezza is Larghezza - H,
    append(Parziale, [[W, H]], NuovoParziale),
    NuoveMattonelleParziali is MattonelleParziali + 1,
    pavimenta(NuovaLunghezza, NuovaLarghezza, NuovoParziale, Pavimentazione, NuoveMattonelleParziali, NumeroMattonelleUtilizzate).

una_pavimentazione_superficie_ottima(Lunghezza, Larghezza, Pavimentazione) :-
    findall(Num, pavimentazione_superficie(Lunghezza, Larghezza, _, Num), Numeri),
    min_list(Numeri, MinMattonelle),
    pavimentazione_superficie(Lunghezza, Larghezza, Pavimentazione, MinMattonelle),!.

% query : pavimentazione_superficie(20, 20, Pavimentazione, NumeroMattonelleUtilizzate).
% query : una_pavimentazione_superficie_ottima(20, 20, Pavimentazione).