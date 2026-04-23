#include<stdio.h>
#include<algorithm>
#define ll long long
#define INF 9223372036854775807
#define m(a,b) a<b?a:b
int a[100];
ll d[100][100001];
int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++)d[i][j]=INF;
    }
    for(i=0;i<=k;i+=a[0]){
        d[0][i]=i/a[0];
    }
    for(i=1;i<n;i++){
        for(j=0;j<a[i];j++)d[i][j]=d[i-1][j];
        for(j=a[i];j<=k;j++){
            d[i][j]=m(d[i-1][j],d[i][j-a[i]]+1);
        }
    }
    /*for(i=0;i<n;i++){
        for(j=1;j<=k;j++)printf("%d ",d[i][j]);
        printf("\n");
    }*/
    if(d[n-1][k]==INF)printf("-1");
    else printf("%lld",d[n-1][k]);
}