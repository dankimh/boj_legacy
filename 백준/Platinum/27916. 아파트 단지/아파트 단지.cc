#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
#ifdef DEBUG
#define in ifs
#define out ofs
#else
#define in cin
#define out cout
#endif // DEBUG

#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
#define arrin(x,n) for(ll qwer=0;qwer<n;qwer++)cin>>x[qwer];
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF=1e18;
constexpr ll mod=1e9+7;
constexpr ll sz=1010101;
ll d[5]= {1,0,-1,0,1};
void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    ll i;
    vector<ll> a(n,0);
    for(i=0;i<n;i++)cin>>a[i];
    vector<ll> xx(n);
    for(i=0;i<q;i++)cin>>xx[i];
    ll st=0,en=a[n-1]+1;
    while(st<en){
        ll x=(st+en)/2;
        vector<int> dp(n+1,0);
        for(i=m-1;i<n;i++){
            auto it=lower_bound(a.begin(),a.end(),a[i]-x)-a.begin();
            //cout<<i<<" "<<it;
            if(it==0){
                dp[i+1]=dp[i]+1;
                //cout<<"x\n";
                continue;
            }
            if(it>i-m+1){
                dp[i+1]=dp[i];
                //cout<<"a\n";
                continue;
            }

            if(dp[i-m+1]-dp[it-1]==0){
                dp[i+1]=dp[i];
                //cout<<"b\n";
                continue;
            }
            else{
                dp[i+1]=dp[i]+1;
                //cout<<"c\n";
                continue;
            }

        }
        bool ch=(dp[n]-dp[n-1]==1);
        if(ch){
            en=x;
        }
        else st=x+1;
    }
    for(i=0;i<q;i++){
        if(xx[i]<st)cout<<"0";
        else cout<<"1";
    }
}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
