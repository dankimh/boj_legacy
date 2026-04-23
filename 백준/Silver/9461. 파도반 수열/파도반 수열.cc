#include<stdio.h>
#define ll unsigned long long
ll p[102]={0,1,1,1,2,2,3,4,5,7,9,12,16,};
ll f(int n){
    if(p[n])return p[n];
    if(n<10)return p[n];
    return p[n]=f(n-1)+f(n-5);
}
int main(){
    int t,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        printf("%lld\n",f(t));
    }
}