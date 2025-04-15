def Somma(l, x):
    i = 0
    j = len(l) - 1

    while i < j :
        if l[j] +l[i] > x:
            j -= 1
        elif l[j] +l[i] < x:
            i += 1

        if l[j]+l[i] == x:
            return [i, j]

    return [-1, -1] 

l = [2,5,9,14,20,21,25,40]
x = 34
print(Somma(l, x))