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
vector<vector<ll>> mp;
vector<ll> p;
vector<ll> fin;
vector<vector<ll>> scc;
stack<ll> s;
ll id=1;
ll dfs(ll node){
    p[node]=id++;
    s.push(node);
    ll parent=p[node];
    for(ll i=0;i<mp[node].size();i++){
        ll next=mp[node][i];
        if(!p[next])parent=min(parent,dfs(next));
        else if(!fin[next])parent=min(parent,p[next]);
    }
    //cout<<node<<" "<<parent<<" "<<p[node]<<"\n";
    if(parent==p[node]){
        vector<ll> imsi;
        while(1){
            ll t=s.top();
            s.pop();
            imsi.push_back(t);
            fin[t]=1;
            if(t==node)break;
        }
        scc.push_back(imsi);
    }
    return parent;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    mp.resize(n+1);
    p.resize(n+1,0);
    fin.resize(n+1,0);
    vector<pair<ll,ll>> edge;
    ll i;
    for(i=0;i<m;i++){
        ll v,w;
        cin>>v>>w;
        edge.push_back({v,w});
        mp[v].push_back(w);
    }
    for(i=1;i<=n;i++){
        if(!p[i])dfs(i);
    }
    /*for(auto& x:scc){
        for(auto& y:x)cout<<y<<" ";
        cout<<"\n";
    }*/
    ll sz=scc.size();
    vector<ll> where(n+1,0);
    for(i=0;i<sz;i++){
        for(ll j=0;j<scc[i].size();j++){
            where[scc[i][j]]=i;
        }
    }
    vector<set<ll>> sccmp(sz+1);
    for(i=0;i<m;i++){
        if(where[edge[i].first]!=where[edge[i].second])sccmp[where[edge[i].first]].insert(where[edge[i].second]);
    }
    vector<ll> incount(sz,0);
    for(i=0;i<sz;i++){
        for(auto& x:sccmp[i]){
            incount[x]++;
        }
    }
    ll st=-1;
    for(i=0;i<sz;i++){
        if(incount[i]==0){
            if(st!=-1){
                cout<<"0";
                return;
            }
            st=i;
        }
    }
    queue<ll> q;
    q.push(st);
    vector<ll> topsort;
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        topsort.push_back(now);
        for(auto& x:sccmp[now]){
            incount[x]--;
            if(incount[x]==0)q.push(x);
        }
    }
    for(i=1;i<topsort.size();i++){
        ll bef=topsort[i-1],now=topsort[i];
        bool flag=binary_search(sccmp[bef].begin(),sccmp[bef].end(),now);
        if(!flag){
            cout<<"0";
            return;
        }
    }
    sort(scc[st].begin(),scc[st].end());
    cout<<scc[st].size()<<"\n";
    for(auto& x:scc[st])cout<<x<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
