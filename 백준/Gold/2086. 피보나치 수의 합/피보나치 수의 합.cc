#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b,ll n){
    int i,j;
    vector<vector<ll>> ans(5,vector<ll> (5));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
            }
            ans[i][j]=(imsi%1000000000);
        }
    }
    return ans;
}
int main(){
    ll n=2,bb,aa;
    vector<vector<ll>> base(5,vector<ll> (5));
    vector<vector<ll>> ans(5,vector<ll> (5));
    ans={{1,0},{0,1}};
    scanf("%lld %lld",&aa,&bb);
    int i,j;
    base={{1,1},{1,0}};
    while(bb){
        if(bb%2){
            ans=f(ans,base,n);
        }
        base=f(base,base,n);
        bb/=2;
    }
    ll ans1=(ans[0][0]+ans[0][1])%1000000000;
    ans={{1,0},{0,1}};
    base={{1,1},{1,0}};
    aa--;
    while(aa){
        if(aa%2){
            ans=f(ans,base,n);
        }
        base=f(base,base,n);
        aa/=2;
    }
    ll ans2=(ans[0][0]+ans[0][1])%1000000000;
    printf("%lld",(ans1-ans2+1000000000)%1000000000);
}