def borsa_cost(l):
    I, J = -1, -1
    diff, m = 0, 0
    i, min = 0, 0
    j, max = 1, 1
    n = len(l)-1

    while j < n:
        if l[i] <= l[min]:
            min = i 
            

        if l[j] >= l[min]:
            max = j
            

        m = l[max] - l[min]
        if m >= diff and max > min:
            I = min
            J = max
            diff = m 
        
        i += 1
        j += 1
        
    return I,J

#l = [20,3,13,11,1,170,52,1,50]
#print(max_diff_cost(l))

def max(l):
    n = len(l) - 1 
    g = [0] * len(l)
    g[0] = 0
    g[n] = n
    j = n - 1

    while j > 0:
        if l[j] > l[g[j+1]]:
            g[j] = j
        else:
            g[j] = g[j+1]
        j -= 1
    return g 
 
def borsa_lin(l):
    i, I, J = 1, -1, -1
    g = max(l)
    t = 0
    n = len(l) - 1

    for i in range(len(l)):
        if l[g[i]] - l[i] > t:
            t = l[g[i]] - l[i]
            I = i 
            J = g[i]
    return I, J
l = [25,20,19,18,17,16,15]
print(borsa_lin(l))
print(borsa_cost(l))







