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
ll n;
vector<pair<ll,ll>> nodes;
vector<pair<ll,ll>> cnt;
vector<ll> loc;
vector<vector<ll>> deps;
pair<ll,ll> dfs(ll node){
    if(nodes[node].first==-1&&nodes[node].second==-1)return cnt[node]={0,0};
    ll l=0,r=0;
    if(nodes[node].first!=-1){
        l++;
        auto x=dfs(nodes[node].first);
        l+=(x.first+x.second);
    }
    if(nodes[node].second!=-1){
        r++;
        auto x=dfs(nodes[node].second);
        r+=(x.first+x.second);
    }
    return cnt[node]={l,r};
}
void d(ll node,ll par,ll dep,ll lr){
    if(lr==0){
        loc[node]=loc[par]-cnt[node].second-1;
    }
    else loc[node]=loc[par]+cnt[node].first+1;
    deps[dep].push_back(node);
    if(nodes[node].first!=-1)d(nodes[node].first,node,dep+1,0);
    if(nodes[node].second!=-1)d(nodes[node].second,node,dep+1,1);
    return;
}
void solve(){
    cin>>n;
    nodes.resize(n+1);
    cnt.resize(n+1);
    loc.resize(n+1);
    deps.resize(n+1);
    ll i,root=n*(n+1)/2;
    for(i=1;i<=n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        nodes[a]={b,c};
        if(b!=-1)root-=b;
        if(c!=-1)root-=c;
    }
    dfs(root);
    loc[0]=n+1;
    d(root,0,1,0);
    ll level=0,width=-1;
    for(i=1;i<=n;i++){
        if(deps[i].size()!=0){
            ll mx=-1,mn=n*2;
            for(auto& x:deps[i]){
                if(mx<loc[x])mx=loc[x];
                if(mn>loc[x])mn=loc[x];
            }
            ll z=mx-mn+1;
            if(width<z){
                width=z;
                level=i;
            }
        }
    }
    cout<<level<<" "<<width;
}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
