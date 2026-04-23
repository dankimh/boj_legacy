#include<bits/stdc++.h>
#define ll long long
constexpr ll mod=1e9+7;
using namespace std;
ll power(ll b,ll ex){
    ll A=1;
    while(ex){
        if(ex%2){
            A=A*b%mod;
        }
        b=b*b%mod;
        ex/=2;
    }
    return A%mod;
}
int main(){
    ll k,n,i,j;
    scanf("%lld %lld",&k,&n);
    ll A=1,B=1;
    for(i=1;i<k+2;i++){
        A=A*i%mod;
        B=B*(n+i-1)%mod;
    }
    ll ans=B*power(A,mod-2)%mod;
    printf("%lld",ans);
}