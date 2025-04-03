def ricMax(l, i, f):
    if i <= f:
        m = (i + f)//2

        if l[m-1] < l[m] and l[m] > l[m+1]:
            return m

        elif l[m+1] > l[m]:
            return ricMax(l, m+1, f)

        elif l[m] > l[m+1]:
            return ricMax(l, i, m-1)

    return -1

#a = [2, 4, 200, 32, 31, 6, 5, 2]
#print(ricMax(a, 0, len(a)-1))

def ordUnimodal(l):
    i = 0
    f = len(l) - 1 
    max = ricMax(l, i, f)
    L = []

    while i < f :
        if l[i] < l[f]:
            L.append(l[i])
            i += 1
        else:
            L.append(l[f])
            f -= 1
    l = L
    return L

a = [2, 4, 200, 32, 31, 6, 5, 2]
print(ordUnimodal(a))



