'''
0 . 0 
s(0) . 1
s(s(0)) . 2 
'''
zero = lambda f: lambda x: x
uno = lambda f: lambda x: f(x)
due = lambda f: lambda x: f(f(x))
tre = lambda f: lambda x: f(f(f(x)))

succ = lambda n: lambda f: lambda x: f((n) (f) (x))
somma = lambda m: lambda n: lambda f: lambda x: m(f)(n(f)(x))


out = succ(succ(tre))(lambda x: x + 1)(0)
print(out)
print(somma(due)(tre)(lambda x: x + 1)(0))
print(somma(uno)(due)(lambda x: x + 1)(0))
'''
(lambda y1: y1 + 1)((lambda y2: y2 + 1)((lambda y: y + 1)(0)))     riduzione successivo
somma = lambda m: lambda n: lambda f: lambda x: m(f)(n(f)(x)) lambda f: lambda x: f(x) lambda f: lambda x: f(f(x))
'''
