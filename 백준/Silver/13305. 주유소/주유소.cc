#include<stdio.h>
#define ll long long
int main(){
    ll n;
    scanf("%lld",&n);
    ll len[100000],i;
    for(i=0;i<n-1;i++)scanf("%lld",&len[i]);
    ll price[100000];
    for(i=0;i<n;i++)scanf("%lld",&price[i]);
    ll minprice=price[0];
    ll ans=0;
    for(i=0;i<n-1;i++){
        if(minprice>price[i])minprice=price[i];
        ans+=minprice*len[i];
    }
    printf("%lld",ans);
}