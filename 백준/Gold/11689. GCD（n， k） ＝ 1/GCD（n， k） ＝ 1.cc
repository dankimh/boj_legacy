#include<stdio.h>
#define ll long long
int main(){
    ll n,a[100];
    scanf("%lld",&n);
    ll ans=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ans/=i;
            ans*=(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1){
        ans/=n;
        ans*=(n-1);
    }
    printf("%lld",ans);
}