#In[1]

def fibonacci_2 (n):
    if n <= 2:
        return 1
    else:
        return fibonacci_2(n-1)+fibonacci_2(n-2)
    
    
print (fibonacci_2(1000))

#In[2]

def fibonacci_3 (n):
    fib = []
    i = 0

    for i in range(n):
        if i < 2:
            fib.append(1)
        else:
            fib.append(fib[i-1] + fib[i-2])
    
    return fib[n-1]

#print (fibonacci_3(6))

#In[3]

def fibonacci_4 (n):
    x, y, z = 1, 1, 0
    i = 2

    while i < n :
        z = y + x
        x = y
        y = z
        i += 1
    return z

#print(fibonacci_4(6))

    

#In[4]



# %%
