def bobble_sort(l):
    if len(l) <= 1:
        return l
    
    for k in range(len(l)):
        for i in range(len(l)-k-1):
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i]
    return l

l = [4,8,9,6,5,7,2,5,4,6,1]
print(bobble_sort(l))
