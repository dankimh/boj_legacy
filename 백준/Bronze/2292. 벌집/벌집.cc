#include<bits/stdc++.h>
int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=0;;i++){
        if(n<=3*i*(i-1)+1)break;
    }
    if(n==1)printf("1");
    else printf("%d",i);
    //printf("%d",(2+(int)round(sqrt((double)(9+12*(n-1))))));
}