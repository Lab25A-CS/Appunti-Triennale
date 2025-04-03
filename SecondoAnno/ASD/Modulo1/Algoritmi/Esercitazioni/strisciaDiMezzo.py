def contaDestra(L):
    n = len(L) - 1
    i, t = 0, 0
    A = []

    while i <= n:
        if L[i] < 0:
            break
        A.append(None)
        i += 1

    while i <= n:
        if L[i] < 0:
            t = 0
        else:
            t += L[i]
        A.append(t)
        i += 1
    return A 

def contaSinistra(L):
    n = len(L) - 1
    i, t = n, 0
    B = [0]*len(L)

    while i >= 0:
        if L[i] < 0:
            break
        B[i] = None
        i -= 1

    while i >= 0:
        if L[i] < 0:
            t = 0
            
        else:
            t += L[i]

        B[i] = t
        i -= 1

    return B

def strisciaDiMezzo (L):
    A = contaDestra(L)
    B = contaSinistra(L)
    C = []
    n, x = len(L) - 1, 0

    for x in range(len(L)): 
        if B[x] == None: 
            C.append(A[x])
        elif A[x] == None:
            C.append(B[x])
        elif B[x] < A[x]:
            C.append(B[x])
        else:
            C.append(A[x])

    return C 

l = [1,4,-1,7,-1,-1,6,3,5,2,-1]
print (strisciaDiMezzo(l))
