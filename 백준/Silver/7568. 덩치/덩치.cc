#include<stdio.h>
int main(){
    int n,i;
    int a[50],b[50],c[50]={0,};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    int j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(a[i]>a[j]&&b[i]>b[j])c[j]++;
        }
    }
    for(i=0;i<n;i++)printf("%d ",c[i]+1);
}
