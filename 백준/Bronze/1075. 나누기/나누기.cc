#include<bits/stdc++.h>
int main(){
    int n,f,i;
    scanf("%d %d",&n,&f);
    for(i=(n/100)*100;i<(n/100)*100+100;i++){
        if(i%f==0){printf("%02d",i%100);break;}
    }
}