#include<bits/stdc++.h>
int main(){
    int x;
    scanf("%d",&x);
    int i;
    for(i=0;i*(i+1)/2<x;i++){
        continue;
    }
    if(i%2==0)printf("%d/%d",i-(i*(i+1)/2-x),i*(i+1)/2-x+1);
    else printf("%d/%d",i*(i+1)/2-x+1,i-(i*(i+1)/2-x));
}