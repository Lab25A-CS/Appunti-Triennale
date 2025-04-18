relazione(mario, luca, "amico").
relazione(luca, anna, "parente").
relazione(anna, giuseppe, "collega").
relazione(mario, paolo, "amico").
relazione(paolo, francesca, "collega").


catena_conoscenza(P1, P2, [P1|Catena]) :-
    relazione(P1, P2, _),    % P1 e P2 si conoscono direttamente
    Catena = [P2].
    
catena_conoscenza(P1, P2, [P1|Catena]) :-
    relazione(P1, X, _),     % P1 ha una relazione di conoscenza con un'altra persona X
    catena_conoscenza(X, P2, Catena),   % X conosce P2 attraverso una catena di conoscenza
    \+ member(P1, Catena),   % P1 non deve essere già presente nella catena
    member(X, [P1|Catena]),!.  % X non deve essere già presente nella catena

