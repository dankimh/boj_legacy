#include<bits/stdc++.h>
using namespace std;
int i,j,a[2000],dp[2000][2000]={0,};
int main(){
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(i==j)dp[j][i]=1;
            else{
                if(a[j]==a[i]){
                    if(j+1>=i-1||dp[j+1][i-1]==1)dp[j][i]=1;
                    else dp[j][i]=0;
                }
                else dp[j][i]=0;
            }
        }
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",dp[s-1][e-1]);
    }
}