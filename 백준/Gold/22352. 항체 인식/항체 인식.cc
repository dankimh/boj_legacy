#include<bits/stdc++.h>
using namespace std;
int n,m;
int ch[30][30];
int sp1[30][30],sp2[30][30];
int dir[5]={1,0,-1,0,1};
void dfs(int x, int y, int val,int ori){
    //printf("%d %d\n",x,y);
    ch[x][y]=1;
    sp1[x][y]=val;
    for(int i=0;i<4;i++){
        int xx=x+dir[i],yy=y+dir[i+1];
        if(xx<0||xx>=n)continue;
        if(yy<0||yy>=m)continue;
        if(sp1[xx][yy]==ori)dfs(xx,yy,val,ori);
    }
    return;
}
int main(){
    cin>>n>>m;
    int check=0;
    bool s=true;

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)cin>>sp1[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)cin>>sp2[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(sp1[i][j]!=sp2[i][j]&&ch[i][j]==0){
                if(check==0){
                    dfs(i,j,sp2[i][j],sp1[i][j]);
                    check=1;
                }
                else{
                    s=false;
                    break;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)if(sp1[i][j]!=sp2[i][j]){
            s=false;
            break;
        }
    }
    if(s)cout<<"YES";
    else cout<<"NO";
}