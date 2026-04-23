#include<stdio.h>
int a[100];
int mem[10001];
int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mem[0]=1;
    for(i=0;i<n;i++){
        for(j=a[i];j<=k;j++){
            mem[j]=mem[j]+mem[j-a[i]];
        }
    }
    printf("%d",mem[k]);
}