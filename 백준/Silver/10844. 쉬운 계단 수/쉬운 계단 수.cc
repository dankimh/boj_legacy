#include<stdio.h>
#include<math.h>
#define mod 1000000000
#define ll long long
int main(){
    ll n,i;
    scanf("%lld",&n);
    ll a[10]={1,1,1,1,1,1,1,1,1,1};
    for(i=1;i<n;i++){
        ll j,imsi[10];
        for(j=0;j<10;j++)imsi[j]=a[j];
        a[0]=imsi[1]%mod;
        for(j=1;j<9;j++){
            a[j]=(imsi[j-1]%mod+imsi[j+1]%mod)%mod;
        }
        a[9]=imsi[8]%mod;
    }
    ll ans=0;
    for(i=1;i<10;i++){ans+=(a[i]%mod);ans%=mod;}
    printf("%lld",(ans+mod)%mod);
}