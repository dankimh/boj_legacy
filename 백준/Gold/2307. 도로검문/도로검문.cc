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
ll d[5]= {1,0,-1,0,1};
vector<vector<pair<ll,ll>>> mp;
ll dijk(ll x,ll y,ll n){
    ll i;
    priority_queue<pair<ll,ll>> q;
    vector<ll> dist(n+1,INF);
    vector<ll> par(n+1,0);
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        auto [cost,now]=q.top();
        q.pop();
        cost=-cost;
        if(cost>dist[now])continue;
        for(i=0;i<mp[now].size();i++){
            ll next=mp[now][i].first;
            ll ncost=cost+mp[now][i].second;
            if(x==now&&y==next)continue;
            if(x==next&&y==now)continue;
            if(dist[next]>ncost){
                par[next]=now;
                dist[next]=ncost;
                q.push({-ncost,next});
            }
        }
    }
    return dist[n];
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    mp.resize(n+1);
    ll i,j;
    for(i=0;i<m;i++){
        ll a,b,t;
        cin>>a>>b>>t;
        mp[a].push_back({b,t});
        mp[b].push_back({a,t});
    }
    priority_queue<pair<ll,ll>> q;
    vector<ll> dist(n+1,INF);
    vector<ll> par(n+1,0);
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        auto [cost,now]=q.top();
        q.pop();
        cost=-cost;
        if(cost>dist[now])continue;
        for(i=0;i<mp[now].size();i++){
            ll next=mp[now][i].first;
            ll ncost=cost+mp[now][i].second;
            if(dist[next]>ncost){
                par[next]=now;
                dist[next]=ncost;
                q.push({-ncost,next});
            }
        }
    }
    if(dist[n]==INF){
        cout<<"-1\n";
        return;
    }
    ll orig=dist[n];
    vector<ll> path;
    ll now=n;
    while(now!=0){
        path.push_back(now);
        now=par[now];
    }
    ll ans=-INF;
    //reverse(path.begin(),path.end());
    //print(path);
    for(i=0;i<path.size()-1;i++){
        ll x=path[i],y=path[i+1];
        ans=max(ans,dijk(x,y,n));
        if(ans==INF){
            cout<<"-1\n";
            return;
        }
    }
    cout<<ans-orig;
}
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
