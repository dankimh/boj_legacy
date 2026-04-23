#include<bits/stdc++.h>
using namespace std;
int d[5]={0,-1,0,1,0};
int main(){
    int m,n,i,j,mx=-1;
    scanf("%d %d",&m,&n);
    vector<vector<int>> mp(n,vector<int> (m));
    queue<pair<int,pair<int,int>>> q;
    for(i=0;i<n;i++)for(j=0;j<m;j++){scanf("%d",&mp[i][j]);if(mp[i][j]==1)q.push({0,{i,j}});}
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int time=q.front().first;
        if(mx<time)mx=time;
        q.pop();
        for(j=0;j<4;j++){
            if(x+d[j]<0||x+d[j]>=n||y+d[j+1]<0||y+d[j+1]>=m)continue;
            if(mp[x+d[j]][y+d[j+1]]==0){
                mp[x+d[j]][y+d[j+1]]=1;

                q.push({time+1,{x+d[j],y+d[j+1]}});
            }
        }
    }
    int ch=1;
    for(i=0;i<n;i++)for(j=0;j<m;j++){
        if(mp[i][j]==0)ch=0;
    }
    if(ch==0)printf("-1");
    else printf("%d",mx);
}