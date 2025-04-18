annunci(5,5,100).
annunci(5,10,123).
annunci(7,10,151).
annunci(10,10,118).
annunci(10,20,259).

%valore_annuncio(5,5,100).
%valore_annuncio(5,10,123).
%valore_annuncio(7,10,151).
%valore_annuncio(10,10,118).
%valore_annuncio(10,20,259).

pagina(50,70).

disposizione_annunci(Disposizione,ValoreEconomico):-
    verifica_dimensioni(Disposizione), %verifica la dimensione totale della disposizione di annunci, se supera la soglia della pagina stampa errore
    valore_tot(Disposizione,ValoreEconomico).

% Verifica se la disposizione è compatibile con le dimensioni della pagina
verifica_dimensioni(Disposizione) :-
    pagina(LunghezzaPagina, LarghezzaPagina),
    area_totale(Disposizione, Lunghezza, Larghezza),
    Lunghezza =< LunghezzaPagina,
    Larghezza =< LarghezzaPagina, !.
verifica_dimensioni(_) :-
    write('Errore: La disposizione degli annunci supera le dimensioni della pagina!'), nl, fail.

% Calcola l'area totale occupata dalla disposizione degli annunci
area_totale([], 0, 0).
area_totale([[W, H]|Resto], Lunghezza, Larghezza) :-
    area_totale(Resto, LunghezzaResto, LarghezzaResto),
    Lunghezza is LunghezzaResto + W,
    Larghezza is max(LarghezzaResto, H).

valore_tot([],0).
valore_tot([[W,H]|Resto],Valore):-
    annunci(W,H,V),
    valore_tot(Resto,ValoreResto),
    Valore is V+ValoreResto.

una_disposizione_annunci_ottima(Disposizione, ValoreEconomico) :-
    findall(V, disposizione_annunci(_, V), Valori),
    max_list(Valori, ValoreEconomico),
    disposizione_annunci(Disposizione, ValoreEconomico).