#include<stdio.h>
#define ll long long
int main(){int t;ll mod=1000000007;scanf("%d",&t);int i;ll a[10001];a[0]=1;for(i=1;i<=10000;i++){a[i]=i*a[i-1];a[i]%=mod;}while(t--){int n;scanf("%d",&n);if(n%2){printf("0\n");continue;}ll ex=mod-2;ll re=1;ll B=(a[n/2]*a[n/2+1])%mod;while(ex){if(ex%2){re*=B;re%=mod;}B*=B;B%=mod;ex/=2;}printf("%lld\n",(re*a[n])%mod);}}