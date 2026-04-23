#include<stdio.h>
#define ll long long
ll m[10][10];
ll f(int a,int b){
    if(a==b)return m[a][b]=1;
    if(b==1)return m[a][b]=a;
    if(b==0)return m[a][b]=1;
    return m[a][b]=f(a-1,b)+f(a-1,b-1);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k));
}