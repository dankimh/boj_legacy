#include<bits/stdc++.h>
#define ch(x,y) if(x<0||x>=n||y<0||y>=m)continue;
#define pii pair<int,int>
constexpr int INF=1<<27;
using namespace std;
vector<string> mp;
vector<vector<pii>> gr;
int d[5]={0,1,0,-1,0},n,m;
int loc(int i,int j){
    return m*i+j;
}
struct cmp{
    bool operator()(pii a,pii b){
        return a.second>b.second;
    }
};
int main(){
    int i,j,k;
    cin>>m>>n;
    mp.resize(n);
    for(i=0;i<n;i++)cin>>mp[i];
    gr.resize(n*m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<4;k++){
                int ni=i+d[k],nj=j+d[k+1];
                ch(ni,nj);
                if(mp[ni][nj]=='1')gr[loc(i,j)].push_back({loc(ni,nj),1});
                else if(mp[ni][nj]=='0')gr[loc(i,j)].push_back({loc(ni,nj),0});
            }
        }
    }
    vector<int> dist(n*m,INF);
    priority_queue<pii,vector<pii>,cmp> q;
    q.push({0,0});
    dist[0]=0;
    while(!q.empty()){
        int now=q.top().first;
        int d=q.top().second;
        q.pop();
        if(dist[now]<d)continue;
        for(auto &i:gr[now]){
            if(d+i.second<dist[i.first]){
                q.push({i.first,d+i.second});
                dist[i.first]=d+i.second;
            }
        }
    }
    printf("%d",dist[n*m-1]);
}