
def insertion_sort(l):
    k = 1
    n = len(l)

    while k < n:
        i = 0
        for i in range(k):
            if l[k] < l[i]:
                l[k], l[i] = l[i], l[k]
            i += 1
        k += 1
        
    
    return l

l = [4,8,9,6,5,7,2,5,4,6,1]
print (insertion_sort(l))    










    

