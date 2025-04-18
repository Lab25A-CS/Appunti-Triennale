# Lambda espressione:
#   'simbolo lambda''variabile''funzione':
#   λ x: x+5
# beta riduzione: calcolo effettivo della lambda espressione:
#   (λ x: x+5)(7) significa: calcolo l'espressione lambda sostituendo a x il valore 7
# alpha equivalenza : cambiare il nome delle variabili e lasciare invariata la funzione:
#   λ x: x+5 diventa λ y: y+5 (stessa cosa)

'''Esempio
f = lambda x,y:x*y+5
k = f(10,8)
print(k)'''

'''q = lambda x:x**2
d = lambda x:x+5
kq = q(d(10)) # funzione composta
print(kq)
'''
l=[(1,2),(1,1),(8,2),(7,1),(2,3)]
ls = sorted(l,key=lambda x:x[0]+x[1])
lp = sorted(l,key=lambda x:x[0]*x[1])
print(f'Lista normale: \t{l}\nLista somme: \t{ls}\nListe prodotti:\t{lp}')
print("---------------------")
s=[("mario","rossi"),("maria","bianchi"),("dino","neri"),("rino","verdi"),("pina","giallini")]
s1 = sorted(s,key=lambda x:len(x[0]+x[1]))
print(f'Lista normale: \t\t{s}\nSomma per caratteri:\t{s1}')