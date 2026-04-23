#include<stdio.h>
#define ll long long
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
     int t,i;
     scanf("%d",&t);
     for(i=0;i<t;i++){
        ll k,c;
        ll r0,r1;
        ll s0,s1;
        ll t0,t1;
        ll q;
        scanf("%lld %lld",&k,&c);
        if(gcd(k,c)!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        else if(k==1){
            if(c==1){printf("2\n");continue;}
            printf("1\n");continue;
        }
        else if(c==1){
            if(k>=1000000000){
                printf("IMPOSSIBLE\n");
                continue;
            }
            printf("%lld\n",k+1);
            continue;
        }
        else{
            ll temp;
            r0=k;r1=c;
            s0=1;s1=0;
            t0=0;t1=1;
            while(r1>0){
                q=r0/r1;
                temp=r0;
                r0=r1;
                r1=temp-r0*q;

                temp=s0;
                s0=s1;
                s1=temp-s0*q;

                temp=t0;
                t0=t1;
                t1=temp-t0*q;
            }
            if(t0<0)t0+=k;
            printf("%lld\n",t0);
        }
     }
}