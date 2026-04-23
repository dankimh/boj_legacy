#include<stdio.h>
#define max(a,b) a>b?a:b
int n,a[301],mx=-1,mem[301][3];
int f(int now,int mod){
    if(mem[now][mod])return mem[now][mod];
    if(now>n){
        return -0xffffff;
    }
    if(mod>2){
        if(now==n)return -0xffffff;
        else return 0;
    }
    if(now==n)return a[n];
    return mem[now][mod]=max(f(now+1,mod+1)+a[now],f(now+2,1)+a[now]);
}
int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("%d",f(0,0));
    /*for(i=0;i<3;i++){
        for(int j=0;j<=n;j++)printf("%d ",mem[j][i]);
        printf("\n");
    }*/

}