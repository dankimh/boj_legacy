#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[8][3]=
{
    {1,2,3},{1,2,4},{1,3,5},{1,4,5},{6,2,3},{6,2,4},{6,3,5},{6,4,5}
};
ll d[12][2]=
{
    {1,2},{1,3},{1,4},{1,5},{6,2},{6,3},{6,4},{6,5},{2,3},{3,5},{5,4},{4,2}
};
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(7,123);
    ll i;
    ll sum=0;
    for(i=1;i<=6;i++){cin>>a[i];sum+=a[i];}
    if(n==1){
        cout<<sum-*max_element(a.begin()+1,a.end());
    }
    else{
        vector<ll> tt(8);
        vector<ll> zz(12);
        ll i;
        for(i=0;i<8;i++){
            tt[i]=a[t[i][0]]+a[t[i][1]]+a[t[i][2]];
        }
        for(i=0;i<12;i++){
            zz[i]=a[d[i][0]]+a[d[i][1]];
        }
        cout<<(5*(n-2)*(n-2)+4*(n-2))*(*min_element(a.begin(),a.end()))+(8*(n-2)+4)*(*min_element(zz.begin(),zz.end()))+4*(*min_element(tt.begin(),tt.end()));
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
}