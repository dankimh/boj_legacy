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
    cout.precision(5);
    ll n,m;
    cin>>n>>m;
    ll i;
    vector<pair<ll,ll>> a(n);
    ll x=0,y=0;
    for(i=0;i<n;i++){
        ll p,q;
        cin>>p>>q;
        x+=p*q;
        y+=q;
        a[i]={p,q};
    }
    sort(a.begin(),a.end());
    if(x==y*m){
        cout<<(ld)y;
        return;
    }
    else if(x<y*m){//erase small
        for(i=0;i<n;i++){
            x-=a[i].first*a[i].second;
            y-=a[i].second;
            if(x<y*m)continue;
            else{
                ld p=(ld)(x-m*y)/(ld)(m-a[i].first);
                cout<<(ld)y+p;
                return;
            }
        }
        cout<<y;
        return;
    }
    else{
        for(i=n-1;i>=0;i--){
            x-=a[i].first*a[i].second;
            y-=a[i].second;
            if(x>y*m)continue;
            else{
                ld p=(ld)(x-m*y)/(ld)(m-a[i].first);
                cout<<(ld)y+p;
                return;
            }
        }
        cout<<y;
        return;
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
