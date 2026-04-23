import sys
from decimal import *
D=Decimal
getcontext().prec=200
input=sys.stdin.readline
def f(a:D, b:D, c:D, d:D, x:D):
    return a*x*x*x+b*x*x+c*x+d
def fp(a:D, b:D, c:D, d:D, x:D):
    return 3*a*x*x+2*b*x+c
def deciequal(a:D, b:D):
    if a>b+D('-0.0000000000000000000001') and a<b+D('0.0000000000000000000001'):
        return True
    else:
        return False
def det(a:D,b:D,c:D,d:D):
    return b*b*c*c-4*a*c*c*c-4*b*b*b*d-27*a*a*d*d+18*a*b*c*d
def p(a:D,b:D,c:D):#-det2
    return (3*a*c-b*b)
#print(D('0'),D('0.00000000000'),"xx")
for i in range(int(input())):
    #print(i,"x")
    intervals=[]
    ans=[]
    a,b,c,d=map(D,input().split())
    #if p(a,b,c)<D('0') or deciequal(p(a,b,c),D('0')):
    #print(p(a,b,c),"what")
    if p(a,b,c)<D('0'):
        x1=((-2)*b+2*(b*b-3*a*c).sqrt())/(6*a)
        x2=((-2)*b-2*(b*b-3*a*c).sqrt())/(6*a)
        x1,x2=min([x1,x2]),max([x1,x2])
        ch=0
        if deciequal(D('0'),f(a,b,c,d,x1)):
            ch=1
        elif deciequal(D('0'),f(a,b,c,d,x2)):
            ch=2
        #print(ch,'ch')
        if a<D('0'):

            if ch==1:
                ans.append(x1)
                intervals.append([x2,D('1000001'),0])
            elif ch==2:
                ans.append(x2)
                intervals.append([D('-1000001'),x1,0])
            elif f(a,b,c,d,x1)>D('0'):
                intervals.append([x2,D('1000001'),0])
            elif f(a,b,c,d,x2)<D('0'):
                intervals.append([D('-1000001'),x1,0])
            else:
                intervals.append([D('-1000001'),x1,0])
                intervals.append([x1,x2,1])
                intervals.append([x2,D('1000001'),0])
        else:
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
        if a<D('0'):
            intervals.append([D('-1000001'),D('1000001'),0])
        else:
            intervals.append([D('-1000001'),D('1000001'),1])

    """for i in range(-1000001,1000001):
        x1=f(a,b,c,d,D(i))
        x2=f(a,b,c,d,D(i+1))
        if deciequal(x1,D('0')):
            ans.append(D(i))
        if (x1<D('0')) and (x2>D('0')):
            #print(D(i),D(i+1),"xx1")
            intervals.append([D(i),D(i+1),1])#up
        if (x1>D('0')) and (x2<D('0')):
            #print(D(i),D(i+1),"xx2")
            intervals.append([D(i),D(i+1),0])#down"""
    #for st,en,updown in intervals:
        #print(st,en,updown)
    for st,en,updown in intervals:
        for i in range(100):
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
    for a in ans:
        a=round(a,15)
    print(' '.join(map(lambda x: f'{x:.10f}', ans)))
    #print('xas')