#include<stdio.h>
#define ll long long
int main(){
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    a%=c;
    ll ans=1;
    while(b){
        if(b%2){
            ans*=a;
            ans%=c;
        }
        a*=a;
        a%=c;
        b/=2;
    }
    printf("%lld",ans%c);
}