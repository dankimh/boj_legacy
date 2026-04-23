#include<bits/stdc++.h>
#include<numeric>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("input.txt");ofs.open("output.txt");
#ifdef DEBUGs
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG
#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
void solve(){
    //DEBUG;
    ll n,i;
    in>>n;
    vector<ll> a(n);
    for(i=0;i<n;i++)in>>a[i];
    vector<ll> lcs(n);
    vector<ll> cnt;
    for(i=0;i<n;i++){
        if(cnt.empty()||a[i]>cnt.back()){
            cnt.push_back(a[i]);
            lcs[i]=cnt.size();
        }
        else{
            auto it=lower_bound(cnt.begin(),cnt.end(),a[i])-cnt.begin();
            cnt[it]=a[i];
            lcs[i]=it+1;
        }
    }
    ll sz=cnt.size();
    //print(cnt);
    vector<vector<ll>> dp(sz+1),ai(sz+1);

    for(i=0;i<=sz;i++)dp[i].push_back(0);
    //print(lcs);
    for(i=0;i<n;i++){
        ll val=1;
        if(lcs[i]>1){
            auto it=upper_bound(ai[lcs[i]-1].begin(),ai[lcs[i]-1].end(),a[i],greater<ll>())-ai[lcs[i]-1].begin();
            val=(dp[lcs[i]-1].back()-dp[lcs[i]-1][it]+mod)%mod;
            //cout<<i<<" "<<it<<"x\n";
        }
        ai[lcs[i]].push_back(a[i]);//always smaller
        //cout<<i<<" "<<val<<"x\n";
        dp[lcs[i]].push_back((val+dp[lcs[i]].back())%mod);

    }
    //cout<<"y";
    out<<sz<<" "<<(dp[sz].back()+mod)%mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
