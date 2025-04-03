def selection_sort(l):
    if len(l) <= 1:
        return l
    
    for k in range (len(l)):
        i = k+1
        for i in range(len(l)):
            if l[i] > l[k]:
                l[i], l[k] = l[k], l[i]
    return l

l = [4,8,9,6,5,7,2,5,4,6,1]
print(selection_sort(l))