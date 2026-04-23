#include<bits/stdc++.h>
int main(){
    int a,i,j,m=0,c,k;
    for(i=0;i<5;i++){
        c=0;
        for(j=0;j<4;j++){
            scanf("%d",&a);
            c+=a;
        }
        if(m<c){m=c;k=i+1;}
    }
    printf("%d %d",k,m);
}
