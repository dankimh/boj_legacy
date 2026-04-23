#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b,ll n){
    int i,j;
    vector<vector<ll>> ans(5,vector<ll> (5));
    /*for(i=0;i<n;i++){
            for(j=0;j<n;j++)printf("%lld ",b[i][j]%1000);
            printf("\n");
        }*/
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
                //printf("%d %d %d %d\n",i,k,k,j);
            }
            //printf("a%lld\n",imsi);
            ans[i][j]=(imsi%1000);
        }
    }
    return ans;
}
int main(){
    ll n,bb;
    vector<vector<ll>> base(5,vector<ll> (5));
    vector<vector<ll>> ans(5,vector<ll> (5));
    ans={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
    scanf("%lld %lld",&n,&bb);
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lld",&base[i][j]);
    while(bb){
        /*for(i=0;i<n;i++){
            for(j=0;j<n;j++)printf("%lld ",ans[i][j]%1000);
            printf("\n");
        }*/
        if(bb%2){
            ans=f(ans,base,n);
        }
        base=f(base,base,n);
        bb/=2;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)printf("%lld ",ans[i][j]%1000);
        printf("\n");
    }
}
