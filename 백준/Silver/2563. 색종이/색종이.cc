#include<bits/stdc++.h>
int a[100][100];
int main(){
    int n,i,x,y,j,k,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        for(j=0;j<10;j++){
            for(k=0;k<10;k++){
                a[j+x-1][k+y-1]=1;
            }
        }
    }
    for(i=0;i<100;i++)for(j=0;j<100;j++)c+=a[i][j];
    printf("%d",c);
}
