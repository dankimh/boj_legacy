#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b){
    int n=2;
    int i,j;
    vector<vector<ll>> ans(5,vector<ll> (5));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
                //printf("%d %d %d %d\n",i,k,k,j);
            }
            //printf("a%lld\n",imsi);
            ans[i][j]=(imsi%1000000007);
        }
    }
    return ans;
}
int main(){
    ll n,bb;
    vector<vector<ll>> base(2,vector<ll> (2));
    vector<vector<ll>> ans(2,vector<ll> (2));
    base={{1,1},{1,0}};
    ans={{1,0},{0,1}};
    scanf("%lld",&n);
    int i,j;
    while(n){
        if(n%2){
            ans=f(ans,base);
        }
        base=f(base,base);
        n/=2;
    }
    printf("%lld",ans[0][1]%1000000007);
}