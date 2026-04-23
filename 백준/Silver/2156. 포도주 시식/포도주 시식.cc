#include<stdio.h>
#include<algorithm>
#define max(a,b) a>b?a:b
int n,a[10001],mx=-1,mem[10001][3];
int f(int now,int mod){
    if(mem[now][mod]>-1)return mem[now][mod];
    if(now>n){
        return 0;
    }
    if(mod>2){
        return 0;
    }
    if(now==n)return a[n];
    int maxval=f(now+1,mod+1)+a[now];
    for(int i=now+2;i<=n;i++){
        maxval=max(maxval,f(i,1)+a[now]);
    }
    return mem[now][mod]=maxval;
}
int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=0;i<=n;i++){
        for(int j=0;j<3;j++)mem[i][j]=-1;
    }
    printf("%d\n",f(0,0));
}
