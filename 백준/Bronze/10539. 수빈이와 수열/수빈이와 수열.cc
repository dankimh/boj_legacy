#include<bits/stdc++.h>
int main(){
    int n,b[100],i,j,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<n;i++){
        a[i]=(i+1)*b[i];
        for(j=0;j<i;j++){
            a[i]-=a[j];
        }
    }
    for(i=0;i<n;i++)printf("%d ",a[i]);
}