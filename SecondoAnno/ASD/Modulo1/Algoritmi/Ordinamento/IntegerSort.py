def integerSort(l):

    max = l[0]   #ritrovamento del massimo
    for i in l:
        if max <= i:
            max = i
    
    x = [0]*(max+1) #creazione array di appoggio
    
    for c in l:
        x[c] += 1  #popolazione dell'array di appoggio con incremento di valore nella posizione equivalente ad un valore nell'array iniziale
    
    t, j = 0, 0

    for t in range(max+1): #scorre array di appoggio
        while x[t] > 0: 
            l[j] = t #l[j] diventa la posizione dell'array di appoggio quando ha un valore superiore a quello di 1
            x[t] -= 1
            j += 1
    return l

l = [4,1,3,2,16,9,10,14,8,7]
print(integerSort(l))
