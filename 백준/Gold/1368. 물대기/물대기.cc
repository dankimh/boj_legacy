#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> p;
vector<pair<int,pair<int,int>>> mp;
int f(int x){
    if(x==p[x])return x;
    else return p[x]=f(p[x]);
}
void u(int x,int y){
    x=f(x);
    y=f(y);
    if(x!=y)p[x]=y;
}
int main(){
    int n,i,j;
    cin>>n;
    mp.resize(n+1);
    p.resize(n+1,0);
    for(i=0;i<n;i++){
        p[i+1]=i+1;
        int x;
        cin>>x;
        mp.push_back({x,{0,i+1}});
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            int x;
            cin>>x;
            if(i==j)continue;
            mp.push_back({x,{i,j}});
        }
    }
    sort(mp.begin(),mp.end());
    ll cnt=0,ans=0;
    i=0;
    while(cnt<=n&&i<mp.size()){
        int val=mp[i].first;
        int st=mp[i].second.first;
        int en=mp[i].second.second;
        if(f(st)!=f(en)){
            u(st,en);
            ans+=val;
            cnt++;
        }
        i++;
    }
    cout<<ans;
}
