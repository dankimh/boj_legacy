#include<bits/stdc++.h>
int main(){
    int n,i,k;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        if(n%i==0)k--;
        if(k==0)break;
    }
    if(k!=0)printf("0");
    else printf("%d",i);
}
