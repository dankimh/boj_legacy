#include<stdio.h>
#include<stdlib.h>
#define ll long long
ll a[10000],b[10000];
ll f(int n){
    return (a[0]*b[n]+a[n]*b[n+1]+a[n+1]*b[0]-a[n]*b[0]-a[n+1]*b[n]-a[0]*b[n+1]);
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
    }
    ll sum=0;
    for(i=1;i<n-1;i++){
        sum+=f(i);
    }
    sum=abs(sum);
    printf("%.1lf",(double)sum/2);
}