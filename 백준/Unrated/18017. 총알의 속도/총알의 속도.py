import sys
from decimal import *
D=Decimal
getcontext().prec=200
input=sys.stdin.readline
c=D('299792458')
a,b=(input().split())
A,B=D(a),D(b)
print((A+B)/(1+(A*B)/(c*c)))