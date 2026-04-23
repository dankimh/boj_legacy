#include<stdio.h>
#define ll long long
#define INF 1000000001
ll a[101][101];
char ans[200];
void f(ll x,ll y,ll k,int turn){
    if(x==0&&y==0)return;
    if(x==0&&y!=0){
        printf("z");
        f(x,y-1,k-1,turn+1);
    }
    else if(x!=0&&y==0){
        printf("a");
        f(x-1,y,k,turn+1);
    }
    else{
        if(a[x-1][y]>=k){
            printf("a");
            f(x-1,y,k,turn+1);
        }
        else{
            printf("z");
            f(x,y-1,k-a[x-1][y],turn+1);
        }
    }
}
int main(){
    ll n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    int i,j;
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            if(i==0||j==0)a[i][j]=1;
            else a[i][j]=a[i-1][j]+a[i][j-1];
            if(a[i][j]>1000000000)a[i][j]=INF;
        }
    }
    if(a[n][m]<k)printf("-1");
    else f(n,m,k,0);
}