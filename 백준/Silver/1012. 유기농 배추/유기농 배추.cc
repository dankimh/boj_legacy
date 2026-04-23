#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int d[5]={0,1,0,-1,0};
void f(int x,int y,vector<vector<int>> &mp,int m,int n){
    int i;
    for(i=0;i<4;i++){
        int nx=x+d[i];
        int ny=y+d[i+1];
        if(nx<0||nx>=m||ny<0||ny>=n)continue;
        if(mp[nx][ny]==1){mp[nx][ny]=0;f(nx,ny,mp,m,n);}
    }
    return;
}
void solve(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    vector<vector<int>> mp(m,vector<int> (n,0));
    int i,j,cnt=0;
    for(i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        mp[a][b]=1;
    }
    for(i=0;i<m;i++)for(j=0;j<n;j++){
        if(mp[i][j]==1){
            mp[i][j]=0;
            f(i,j,mp,m,n);
            cnt++;
        }
    }
    printf("%d\n",cnt);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
}