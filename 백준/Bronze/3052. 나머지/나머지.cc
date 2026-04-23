#include<bits/stdc++.h>
int a[43],i,b,c=0;
int main(){
    for(i=0;i<10;i++){
        scanf("%d",&b);
        a[b%42]=1;
    }
    for(i=0;i<43;i++)c+=a[i];
    printf("%d",c);
}