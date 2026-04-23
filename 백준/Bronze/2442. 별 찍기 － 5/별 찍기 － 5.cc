#include<bits/stdc++.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++,printf("\n")){
        for(j=0;j<n+i;j++){
            if(j>=n-i-1&&j<=n+i-1)printf("*");
            else printf(" ");
        }
    }
}
