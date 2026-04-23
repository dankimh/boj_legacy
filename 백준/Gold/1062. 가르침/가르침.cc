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
void solve(){
    ll n,k,i;
    cin>>n>>k;
    vector<string> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    if(k<5){
        cout<<"0\n";
        return;
    }
    ll ans=0;
    for(i=0;i<(1ll<<26);i++){
        if((i&532741)!=532741)continue;
        if(__builtin_popcountll(i)!=k)continue;
        ll cnt=0;
        for(ll j=0;j<n;j++){
            bool flag=true;
            for(ll l=4;l<a[j].size()-4;l++){
                if((i&(1ll<<(a[j][l]-'a')))==0){
                    flag=false;
                    break;
                }
            }
            if(flag)cnt++;
        }
        if(ans<cnt)ans=cnt;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
