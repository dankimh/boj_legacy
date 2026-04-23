#include<bits/stdc++.h>
using namespace std;
vector<int> p;
int f(int u){
    if(u==p[u])return u;
    else return p[u]=f(p[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    p[u]=v;
    return;
}
int main(){
    int n,m,i;
    cin>>n>>m;
    p.resize(n+1);
    vector<pair<int,pair<int,int>>> mp;
    for(i=1;i<=n;i++)p[i]=i;
    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp.push_back({c,{a,b}});
    }
    sort(mp.begin(),mp.end());
    int ans=0,cnt=0;
    for(i=0;i<m;i++){
        if(cnt>n-1)break;
        int a=mp[i].second.first;
        int b=mp[i].second.second;
        int c=mp[i].first;
        //cout<<a<<" "<<b<<" "<<c<<"\n";
        if(f(a)==f(b))continue;
        else{
            uni(a,b);
            ans+=c;
            cnt++;
        }
    }
    cout<<ans;
}