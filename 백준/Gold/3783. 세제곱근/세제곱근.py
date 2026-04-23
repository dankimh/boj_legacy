from decimal import *
D=Decimal
t=int(input())
for a in range(0,t):
    getcontext().prec=300
    n=input()
    n=D(n)
    x=(D(n)**D(D('1.0')/D('3.0')))
    x=round(x,150)
    x=str(x)
    #print(x)
    xs=x.split('.')
    print(xs[0]+'.'+xs[1][:10])