#include<bits/stdc++.h>
#define ch(x,y) if(x<0||x>=hh||y<0||y>=ww)continue;
constexpr int INF=1<<27;
using namespace std;
typedef pair<int,int> pii;
int d[5]={0,1,0,-1,0},hh,ww;
vector<string> mp;
vector<vector<pii>> gr;
vector<int> prisoner;
vector<int> goal;
int loc(int i,int j){
    return ww*i+j;
}
vector<int> djik(int loc){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<int> dist(hh*ww,INF);
    q.push({0,loc});
    dist[loc]=0;
    while(!q.empty()){
        int now=q.top().second;
        int d=q.top().first;
        q.pop();
        if(d>dist[now])continue;
        for(auto &i:gr[now]){
            int nn=i.first;
            int nd=i.second+d;
            if(nd<dist[nn]){
                q.push({nd,nn});
                dist[nn]=nd;
            }
        }
    }
    return dist;
}
void solve(){
    int i,j,k;
    int h,w;
    cin>>h>>w;
    mp.clear();
    prisoner.clear();
    gr.clear();
    goal.clear();
    mp.resize(h+2);
    hh=h+2;ww=w+2;
    for(i=1;i<=h;i++)cin>>mp[i];
    for(i=0;i<w+2;i++){mp[0]+='.';mp[h+1]+='.';}
    for(i=1;i<=h;i++){
        mp[i].insert(0,1,'.');
        mp[i]+='.';
    }
    for(i=0;i<hh;i++){
        for(j=0;j<ww;j++){
            if(mp[i][j]=='$'){
                prisoner.push_back(loc(i,j));
            }
        }
    }
    int siz=(int)goal.size();
    gr.resize(hh*ww);
    for(i=0;i<hh;i++){
        for(j=0;j<ww;j++){
            for(k=0;k<4;k++){
                int ni=i+d[k],nj=j+d[k+1];
                ch(ni,nj);
                if(mp[ni][nj]=='#')gr[loc(i,j)].push_back({loc(ni,nj),1});
                else if(mp[ni][nj]=='.'||mp[ni][nj]=='$')gr[loc(i,j)].push_back({loc(ni,nj),0});
                else if(mp[ni][nj]=='*')gr[loc(i,j)].push_back({loc(ni,nj),INF});
            }
        }
    }
    auto ans1=djik(prisoner[0]);
    auto ans2=djik(prisoner[1]);
    auto ans3=djik(0);
    int mn=INF;
    for(i=0;i<hh*ww;i++){
        int x=ans1[i]+ans2[i]+ans3[i];
        if(mp[i/ww][i%ww]=='#')x-=2;
        mn=min(mn,x);
    }
    printf("%d\n",mn);
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        solve();

    }


}