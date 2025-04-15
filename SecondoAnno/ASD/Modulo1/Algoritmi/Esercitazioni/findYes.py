def ricEi(l, i, f):
    if i < f:
        m = (i + f)// 2

        if l[m] == 'E' and l[m-1] == 'Y':
            return m

        elif l[m] == 'E' or l[m] == 'S':
            return ricEi(l, i, m-1)

        elif l[m] == 'Y':
            return ricEi(l, m+1, f)

def ricEf(l, i, f):
    if i < f:
        m = (i + f)// 2

        if l[m] == 'E' and l[m+1] == 'S':
            return m

        elif l[m] == 'S':
            return ricEf(l, i, m-1)

        elif l[m] == 'E' or l[m] == 'Y':
            return ricEf(l, m+1, f)

def findYes(l):
    i = 0
    f = len(l) - 1

    ei = ricEi(l, i, f)
    ef = ricEf(l, i, f)

    S = len(l) - (ef) -1
    E = ef - ei -1
    Y = len(l) - S - E 

    return Y, E, S

a = ['Y','Y','E','E','E','E','S','S','S','S']
print (findYes(a))
