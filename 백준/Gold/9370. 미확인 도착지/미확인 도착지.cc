#include<bits/stdc++.h>
using namespace std;
constexpr int INF=1<<29;
vector<vector<pair<int,int>>> mp;
vector<int> dijk(int n,int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    vector<int> dist(n+1,INF);
    dist[start]=0;
    while(!q.empty()){
        int now=q.top().second;
        int dst=q.top().first;
        q.pop();
        //cout<<now<<" "<<dst<<" "<<start<<"\n";
        if(dist[now]<dst)continue;
        for(auto &i:mp[now]){
            //cout<<i.first<<"x"<<i.second<<"\n";;
            if(dist[i.first]>dst+i.second){
                dist[i.first]=dst+i.second;
                q.push({dst+i.second,i.first});
            }
        }
    }
    return dist;
}
void solve(){
    int n,m,t;
    cin>>n>>m>>t;
    mp.clear();
    mp.resize(n+1);
    vector<int> dest;
    int s,g,h;
    cin>>s>>g>>h;
    int i;
    int sai;
    for(i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        if((a==g&&b==h)||(a==h&&b==g))sai=d;
        mp[a].push_back({b,d});
        mp[b].push_back({a,d});
    }
    for(i=0;i<t;i++){
        int x;
        cin>>x;
        dest.push_back(x);
    }
    auto dist=dijk(n,s);
    auto distg=dijk(n,g);
    auto disth=dijk(n,h);
    /*for(auto &i:dist){
        cout<<i<<" ";
    }
    cout<<"a\n";*/
    vector<int> ans;
    for(auto &i:dest){
        int a1=(dist[i]==dist[g]+sai+disth[i]);
        int a2=(dist[i]==dist[h]+sai+distg[i]);
        if(a1||a2){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto &i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    int tt;
    cin>>tt;
    while(tt--)solve();
}