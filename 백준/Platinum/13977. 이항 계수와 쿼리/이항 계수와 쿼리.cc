#include<stdio.h>
#define ll long long
int main(){
    int m,i;
    ll mod=1000000007;
    scanf("%d",&m);
    ll a[4000001];
    a[0]=1;
    for(i=1;i<=4000000;i++){
        a[i]=(i*a[i-1])%mod;
    }
    for(int j=0;j<m;j++){
        int n,r;
        scanf("%d %d",&n,&r);
        ll A=a[n];
        ll B=(a[n-r]*a[r])%mod;
        ll ex=mod-2;
        ll re=1;
        while(ex){
            if(ex%2){
                re*=B;
                re%=mod;
            }
            B*=B;
            B%=mod;
            ex/=2;
        }
        printf("%lld\n",(re*A)%mod);
    }
}