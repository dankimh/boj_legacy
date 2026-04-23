#include<stdio.h>
#define ll long long
int main(){
    ll n;
    scanf("%lld",&n);
    ll ex=n,a=2,b=0,c=1,d=1;
    while(ex){
        //printf("a%lld %lld %lld %lld\n",a,b,c,d);
        if(ex%2){
            ll ta=a,tb=b;
            a=(ta*c+5*tb*d)/2;
            b=(ta*d+tb*c)/2;
            a%=10000000;
            b%=10000000;
        }
        ll tc=c,td=d;
        c=((tc*tc+5*td*td)/2)%10000000;
        d=((2*tc*td)/2)%10000000;
        ex/=2;
    }
    ex=n;
    ll p=2,q=0,r=1,s=-1;
    while(ex){
        //printf("a%lld %lld %lld %lld\n",p,q,r,s);
        if(ex%2){
            ll tp=p,tq=q;
            p=(tp*r+5*tq*s)/2;
            q=(tp*s+tq*r)/2;
            p%=10000000;
            q%=10000000;
        }
        ll tr=r,ts=s;
        r=((tr*tr+5*ts*ts)/2)%10000000;
        s=((2*tr*ts)/2)%10000000;
        ex/=2;
    }

    printf("%lld",((b-q)/2)%1000000);
}
