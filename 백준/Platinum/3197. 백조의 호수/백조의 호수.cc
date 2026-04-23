#include<bits/stdc++.h>
#define pii pair<int,int>
#define ch(x,y,j) if(x+d[j]<0||x+d[j]>=r||y+d[j+1]<0||y+d[j+1]>=c)continue;
using namespace std;
int d[5]={0,1,0,-1,0},r,c;
pii parent[1600][1600];
char mp[1600][1600];
pii f(pii u){
    if(parent[u.first][u.second]==u)return u;
    else{
        pii v=f(parent[u.first][u.second]);
        parent[u.first][u.second]=v;
        return v;
    }
}
void uni(pii u,pii v){
    u=f(u);
    v=f(v);
    if(u!=v){
        if(u<v)parent[v.first][v.second]=u;
        else parent[u.first][u.second]=v;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k;
    cin>>r>>c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>mp[i][j];
            parent[i][j]={i,j};
        }
    }
    vector<pii> swan;
    set<pii> next_melt;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(mp[i][j]=='.'){
                for(k=0;k<4;k++){
                    ch(i,j,k);
                    if(mp[i+d[k]][j+d[k+1]]=='.'||mp[i+d[k]][j+d[k+1]]=='L')uni({i,j},{i+d[k],j+d[k+1]});
                }
            }
            if(mp[i][j]=='L'){
                swan.push_back({i,j});
                for(k=0;k<4;k++){
                    ch(i,j,k);
                    if(mp[i+d[k]][j+d[k+1]]=='.'||mp[i+d[k]][j+d[k+1]]=='L')uni({i,j},{i+d[k],j+d[k+1]});
                }
            }
            if(mp[i][j]=='X'){
                for(k=0;k<4;k++){
                    ch(i,j,k);
                    if(mp[i+d[k]][j+d[k+1]]=='.'||mp[i+d[k]][j+d[k+1]]=='L'){
                        next_melt.insert({i,j});
                        //cout<<i<<","<<j<<"\n";
                    }
                }
            }
        }
    }
    int day=0;
    while(1){
        day++;
    //cout<<day<<"d\n";
    //cout<<next_melt.size()<<"s\n";
    /*for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                //cout<<parent[i][j].first<<","<<parent[i][j].second<<" ";
                cout<<mp[i][j];
            }
            cout<<"\n";
        }*/
        set<pii> imsi=next_melt;
        next_melt.clear();
        for(auto& [x,y]:imsi){mp[x][y]='.';}
        for(auto& [x,y]:imsi){
            for(k=0;k<4;k++){
                ch(x,y,k);
                if(mp[x+d[k]][y+d[k+1]]=='.'||mp[x+d[k]][y+d[k+1]]=='L'){
                    uni({x,y},{x+d[k],y+d[k+1]});
                }
                if(mp[x+d[k]][y+d[k+1]]=='X'){
                    next_melt.insert({x+d[k],y+d[k+1]});
                }
            }
        }
        if(f(swan[0])==f(swan[1]))break;
    }
    cout<<day;
}