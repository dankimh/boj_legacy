#include<bits/stdc++.h>
using namespace std;
int ch[40001]={0,};
int i,a[30],dp[30][40001]={0,},sum=0;
int main(){
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
    int j;
    
    dp[0][0]=1;
    dp[0][a[0]]=1;
    for(i=1;i<n;i++){
        for(j=0;j<=sum;j++){
            if(dp[i-1][j])dp[i][j]=1;
            else if(j-a[i]>=0&&dp[i-1][j-a[i]]==1)dp[i][j]=1;
            else if(dp[i-1][j+a[i]]==1)dp[i][j]=1;
            else if(a[i]-j>=0&&dp[i-1][a[i]-j]==1)dp[i][j]=1;
            else dp[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<=sum;j++){
            if(dp[i][j]==1){ch[j]=1;
            //printf("i-%d j-%d - %d ",i,j,dp[i][j]);
            }
        }
        //printf("\n");
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        if(ch[k]==1)printf("Y ");
        else printf("N ");
    }
}