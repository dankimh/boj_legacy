#include<bits/stdc++.h>
using namespace std;
int m,n,h,d[8]={1,0,0,-1,0,0,1,0};
int tomato[100][100][100];
int main(){

    cin>>m>>n>>h;
    int i,j,k,ans=0;

    queue<tuple<int,int,int,int>> q;
    for(i=0;i<h;i++)for(j=0;j<n;j++)for(k=0;k<m;k++){
        cin>>tomato[i][j][k];
        if(tomato[i][j][k]==1)q.push({i,j,k,0});
    }
    while(!q.empty()){
        int z=get<0>(q.front());
        int x=get<1>(q.front());
        int y=get<2>(q.front());
        int day=get<3>(q.front());
        ans=day;
        q.pop();
        for(i=0;i<6;i++){
            int nz=z+d[i];
            int nx=x+d[i+1];
            int ny=y+d[i+2];
            if(nz<0||nz>=h||nx<0||nx>=n||ny<0||ny>=m)continue;
            if(tomato[nz][nx][ny]==0){
                tomato[nz][nx][ny]=1;
                q.push({nz,nx,ny,day+1});
            }
        }
    }

    for(i=0;i<h;i++)for(j=0;j<n;j++)for(k=0;k<m;k++){
        if(tomato[i][j][k]==0){
            cout<<"-1";
            exit(0);
        }
    }
    cout<<ans;
}
