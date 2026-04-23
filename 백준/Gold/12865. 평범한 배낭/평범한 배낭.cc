#include<stdio.h>
int main(){
    int dp[101][100001];
    int n,k,a[1001][2];
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(i=0;i<=k;i++)dp[0][i]=0;
    for(i=0;i<=n;i++)dp[i][0]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(j<a[i][0])dp[i][j]=dp[i-1][j];
            else{
                if(a[i][1]+dp[i-1][j-a[i][0]]>dp[i-1][j])dp[i][j]=a[i][1]+dp[i-1][j-a[i][0]];
                else dp[i][j]=dp[i-1][j];
            }
        }
    }
    /*for(i=0;i<=n;i++){
        for(j=0;j<=k;j++)printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    printf("%d",dp[n][k]);
}