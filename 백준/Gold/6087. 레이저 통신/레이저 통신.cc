#include<bits/stdc++.h>
using namespace std;
const int INF=1<<20;
int d[5]={1,0,-1,0,1};
char direction[4]={'d','l','u','r'};
int main(){
    int w,h;
    cin>>w>>h;
    char mp[101][101];
    int i,j,x=0;
    pair<int,int> start[2];
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='C')start[x++]={i,j};
        }
    }
    int vis[101][101];
    for(i=0;i<101;i++){
        for(j=0;j<101;j++)vis[i][j]=INF;
    }
    queue<pair<pair<int,int>,pair<int,char>>> q;
    int ans=0;
    q.push({start[0],{0,'x'}});
    vis[start[0].first][start[0].second]=0;
    while(!q.empty()){
        pair<int,int> coo=q.front().first;
        int mir=q.front().second.first;
        char dir=q.front().second.second;
        if(vis[coo.first][coo.second]<mir-1)continue;
        q.pop();
        //cout<<coo.first<<" "<<coo.second<<" "<<mir<<" "<<dir<<"\n";
        for(i=0;i<4;i++){
            int nx=coo.first;
            int ny=coo.second;
            while(1){
                nx+=d[i];
                ny+=d[i+1];
                if(nx<0||nx>=h||ny<0||ny>=w)break;
                if(mp[nx][ny]=='*')break;
                if(vis[nx][ny]>mir+1){
                    vis[nx][ny]=mir+1;
                    q.push({{nx,ny},{mir+1,'x'}});
                }
            }
        }
    }
    /*for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cout<<(vis[i][j]==INF?0:vis[i][j])<<" ";
        }
        cout<<"\n";
    }*/
    cout<<vis[start[1].first][start[1].second]-1;
}