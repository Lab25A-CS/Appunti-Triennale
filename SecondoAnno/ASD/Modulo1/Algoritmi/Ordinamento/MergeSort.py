def merge(l,i,c,f):

    l_final = []
    
    k1, k2 = i, c
    while k1 < c and k2 < f :
        if l[k1] <= l[k2]:
            l_final.append(l[k1])
            k1 += 1
        elif l[k2] < l[k1]:
            l_final.append(l[k2])
            k2 += 1
    
    if k1 == c :
        tx, l_prov , p = f, l, k2
    else:
        tx, l_prov , p = c, l, k1
    
    while p < tx:
        l_final.append(l_prov[p])
        p += 1
    
    for m in range(f-i):
        l[i+m] = l_final[m]
    return


def merge_sort(a, lx, rx):
    if rx == lx or rx == lx+1:
        return
    cx = (rx+lx)//2
    merge_sort(a, lx, cx)
    merge_sort(a, cx, rx)
    merge(a, lx, cx, rx)


l = [4,8,9,6,5,7,2,5,4,6,1]
merge_sort(l,0,len(l))
print(l)
