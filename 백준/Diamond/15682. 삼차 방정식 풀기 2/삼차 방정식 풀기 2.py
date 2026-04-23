import sys
from decimal import *
D=Decimal
getcontext().prec=200
input=sys.stdin.readline
def f(a:D, b:D, c:D, d:D, x:D):
    return a*x*x*x+b*x*x+c*x+d
def deciequal(a:D, b:D):
    if (a>b+D('-0.0000000000000000000001')) & (a<b+D('0.0000000000000000000001')):
        return True
    else:
        return False
def p(a:D,b:D,c:D):#-det2
    return (3*a*c-b*b)
for i in range(int(input())):
    intervals=[]
    ans=[]
    a,b,c,d=map(D,input().split())
    if a<D('0'):
        a=-a
        b=-b
        c=-c
        d=-d
    if p(a,b,c)<D('0'):
        x1=((-2)*b+2*(b*b-3*a*c).sqrt())/(6*a)
        x2=((-2)*b-2*(b*b-3*a*c).sqrt())/(6*a)
        x1,x2=min([x1,x2]),max([x1,x2])
        ch=0
        if deciequal(D('0'),f(a,b,c,d,x1)):
            ch=1
        elif deciequal(D('0'),f(a,b,c,d,x2)):
            ch=2
        if ch==1:
            ans.append(x1)
            intervals.append([x2,D('1000001'),1])
        elif ch==2:
            ans.append(x2)
            intervals.append([D('-1000001'),x1,1])
        elif f(a,b,c,d,x1)<D('0'):
            intervals.append([x2,D('1000001'),1])
        elif f(a,b,c,d,x2)>D('0'):
            intervals.append([D('-1000001'),x1,1])
        else:
            intervals.append([D('-1000001'),x1,1])
            intervals.append([x1,x2,0])
            intervals.append([x2,D('1000001'),1])
    else:
        intervals.append([D('-1000001'),D('1000001'),1])
    for st,en,updown in intervals:
        for i in range(60):
            mid=(st+en)/2
            val=f(a,b,c,d,mid)
            if val<0:
                if updown==1:
                    st=mid
                else:
                    en=mid
            else:
                if updown==1:
                    en=mid
                else:
                    st=mid
        ans.append(round(mid,15))
    ans=sorted(ans)
    print(' '.join(map(lambda x: f'{x:.10f}', ans)))