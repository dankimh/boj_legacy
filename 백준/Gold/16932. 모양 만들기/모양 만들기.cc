#include<bits/stdc++.h>
#define X(i,j,k) if(i+d[k]<0||i+d[k]>=n||j+d[k+1]<0||j+d[k+1]>=m)continue;
using namespace std;
typedef long long ll;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};
pair<ll,ll> p[1010][1010];
ll sz[1010][1010];
int d[5]={-1,0,1,0,-1};
pair<ll,ll> f(pair<ll,ll> x){
    if(x==p[x.first][x.second])return x;
    else return p[x.first][x.second]=f(p[x.first][x.second]);
}
void u(pair<ll,ll> a,pair<ll,ll> b){
    a=f(a);
    b=f(b);
    p[b.first][b.second]=a;
    sz[a.first][a.second]+=sz[b.first][b.second];
    sz[b.first][b.second]=0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    int i,j,k;
    vector<vector<int>> mp(n,vector<int>(m));
    for(i=0;i<n;i++)for(j=0;j<m;j++){p[i][j]={i,j};cin>>mp[i][j];if(mp[i][j]==1)sz[i][j]=1;}
    for(i=0;i<n;i++)for(j=0;j<m;j++){
        if(mp[i][j]==1){
            for(k=0;k<4;k++){
                X(i,j,k);
                if(mp[i+d[k]][j+d[k+1]]==1){
                    if(f({i,j})!=f({i+d[k],j+d[k+1]})){
                        u({i,j},{i+d[k],j+d[k+1]});
                    }
                }
            }
        }
    }
    unordered_map<pair<ll,ll>,int,pair_hash> mpp;
    ll mx=0;
    //for(i=0;i<n;i++,puts(""),puts(""))for(j=0;j<m;j++)cout<<sz[i][j]<<" ";//cout<<p[i][j].first<<" "<<p[i][j].second<<" ";
    for(i=0;i<n;i++)for(j=0;j<m;j++){
        if(mp[i][j]==0){
            ll imsz=1;
            vector<int> z(4,0);
            for(k=0;k<4;k++){
                X(i,j,k);
                pair<ll,ll> pa=f({i+d[k],j+d[k+1]});
                if(mpp.count(pa)==0){
                    imsz+=sz[pa.first][pa.second];
                    mpp[pa]=1;
                }
            }
            if(mx<imsz)mx=imsz;
            mpp.clear();
        }
    }
    cout<<mx;
}
