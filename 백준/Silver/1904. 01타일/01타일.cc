#include<stdio.h>
int a[1000001];
int m;
int f(int n){
    if(a[n])return a[n]%15746;
    if(n==1)return 1;
    if(n==2)return 2;
    return a[n]=(f(n-1)+f(n-2))%15746;
}
int main(){
    scanf("%d",&m);
    printf("%d",f(m));
}