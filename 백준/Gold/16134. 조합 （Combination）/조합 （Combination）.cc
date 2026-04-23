#include<stdio.h>
#define ll long long
int main(){
    int n,r;
    ll mod=1000000007;
    scanf("%d %d",&n,&r);
    int i;
    ll A=1,B=1;
    for(i=1;i<=n;i++){
        A*=i;
        A%=mod;
    }
    for(i=1;i<=r;i++){
        B*=i;
        B%=mod;
    }
    for(i=1;i<=n-r;i++){
        B*=i;
        B%=mod;
    }
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
    printf("%lld",(re*A)%mod);
}