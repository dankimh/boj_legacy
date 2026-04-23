#include<bits/stdc++.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,j=0;
    for(i=0;;i++){
        if(n-3*i<0){printf("-1");return 0;}
        if((n-3*i)%5==0){
            j=(n-3*i)/5;
            break;
        }
    }
    printf("%d",i+j);
}
