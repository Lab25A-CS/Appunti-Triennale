def partition(l,i,f):
    x = l[i]
    inf, sup = i+1, f

    while inf < sup:
        while x > l[inf] and sup!=inf:
            inf += 1
        while x <= l[sup]:
            sup -= 1
        if sup < inf:
            break
        l[inf], l[sup] = l[sup], l[inf]
    l[i], l[sup] = l[sup], l[i]
    return sup

def quick_sort(l,i,f):

    if (i < f):
        m = partition(l,i,f)
        quick_sort(l,i,m-1)
        quick_sort(l,m+1,f)
    return l

l = [4,8,9,6,5,7,2,5,4,6,1]
print(quick_sort(l,0,len(l)-1))
