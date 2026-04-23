#include<bits/stdc++.h>
int main(){
    int n,max=0,p;
    int a[1001],i;
    scanf("%d",&n);
    a[n]=0;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    p=a[0];
    for(i=0;i<n;i++){
        if(a[i]>=a[i+1]){
            if(a[i]-p>max){max=a[i]-p;}
            p=a[i+1];
        }
    }
    //if(c==0)max=a[n-1]-p;
    printf("%d",max);
}