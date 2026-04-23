#include<bits/stdc++.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++,printf("\n")){
        for(j=0;j<-i+2*n-1;j++){
            if(j>=i)printf("*");
            else printf(" ");
        }
    }
}
