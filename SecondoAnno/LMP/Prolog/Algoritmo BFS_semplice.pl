edge(a,b).
edge(a,c).
edge(b,d).
edge(b,k).
edge(c,e).
edge(c,d).
edge(c,n).
edge(e,f).
edge(f,f).
edge(f,d).
edge(e,n).
edge(n,a).

bfs(Start,Obiettivo,Percorso):-
    bfs_ricerca([[Start]],Obiettivo,PercorsoReverse),
    reverse(PercorsoReverse,Percorso).

%caso base: il percorso inizia col nodo obiettivo
bfs_ricerca([[Obiettivo|Percorso]|_],Obiettivo,[Obiettivo|Percorso]).

%Esplora nuove frontiere
bfs_ricerca([PercorsoAttuale|Coda],Obiettivo,Percorso):-
    extend(PercorsoAttuale,NuovaFrontiera),
    append(Coda,NuovaFrontiera,NuovaCoda),
    bfs_ricerca(NuovaCoda,Obiettivo,Percorso).

%Estende il percorso attuale con i vicini non ancora visitati (estende frontiere)
extend([Nodo|Percorso],NuoviPercorsi):-
    findall([NuovoNodo,Nodo|Percorso],
            (edge(Nodo,NuovoNodo),
                \+member(NuovoNodo,[Nodo|Percorso])),
            NuoviPercorsi).

%Vedi su libro Prolog Programming for Artificial Intelligence [Ivan Bratko].pdf pagina 252
