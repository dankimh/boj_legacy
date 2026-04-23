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
ll ex(ll a,ll b){
    ll ret=1;
    while(b>0){
        if(b%2){
            ret*=a;
            ret%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }
    return ret;
}
void solve(){
    ll a,b,n;
    cin>>a>>b>>n;
    cout<<ex(2,31*(n-1));
}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
