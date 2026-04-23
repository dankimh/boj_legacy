#include<stdio.h>
#include<stdlib.h>
#define ll long long
int mp[2001][2001];
int nCr(int a, int b, int mod){
    if(mp[a][b])return mp[a][b];
    if(a==b)return mp[a][b]=1%mod;
    if(b==1)return mp[a][b]=a%mod;
    if(b==0)return mp[a][b]=1%mod;

    return mp[a][b]=((nCr(a-1,b,mod))+(nCr(a-1,b-1,mod)))%mod;
}
int main(){
    ll n,k,ncr=1;
    int m;
    scanf("%lld %lld %d",&n,&k,&m);

    while(n>0){
        int a,b;
        a=n%m;
        b=k%m;
        if(a<b){
            ncr=0;
            break;
        }
        ncr*=nCr(a,b,m);
        ncr%=m;
        n/=m;
        k/=m;
    }
    printf("%lld",ncr);
}