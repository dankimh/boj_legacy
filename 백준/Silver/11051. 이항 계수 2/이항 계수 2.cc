#include<stdio.h>
#define ll long long
#define MOD 10007
ll m[1001][1001];
ll f(int a,int b){
    if(m[a][b])return m[a][b];
    if(a==b)return m[a][b]=1;
    if(b==1)return m[a][b]=a%MOD;
    if(b==0)return m[a][b]=1;
    return m[a][b]=(f(a-1,b)+f(a-1,b-1))%MOD;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k)%MOD);
}