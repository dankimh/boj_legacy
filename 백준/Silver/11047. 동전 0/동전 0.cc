#include<stdio.h>
int main(){
    int n,k,i;
    scanf("%d %d",&n,&k);
    int a[10];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    i=n-1;
    int ans=0;
    while(k>0){
        while(k>=a[i]){k-=a[i];ans++;}
        i--;
    }
    printf("%d",ans);
}