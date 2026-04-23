#include<stdio.h>
int r[1000],b[1000],g[1000];
int n;
int a[3][1000];
int min(int x,int y){return x<y?x:y;}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<3;j++)scanf("%d",&a[j][i]);
    }
    r[0]=a[0][0];
    g[0]=a[1][0];
    b[0]=a[2][0];
    for(i=1;i<n;i++){
        //printf("%d %d %d\n",r[i-1],g[i-1],b[i-1]);
        r[i]=a[0][i]+min(g[i-1],b[i-1]);
        g[i]=a[1][i]+min(r[i-1],b[i-1]);
        b[i]=a[2][i]+min(g[i-1],r[i-1]);
    }
    printf("%d",min(min(r[n-1],g[n-1]),b[n-1]));
}