#include<bits/stdc++.h>
using namespace std;
char mp[101][101];
int d[5]{1,0,-1,0,1};
int vis[101][101];
int r,c;
void dfs(int x,int y,int cc){
    //cout<<x<<" "<<y<<" "<<cc<<"y\n";
    vis[x][y]=cc;
    for(int i=0;i<4;i++){
        int nx=x+d[i];
        int ny=y+d[i+1];
        if(nx<0||nx>=r||ny<0||ny>=c)continue;
        //cout<<nx<<" "<<ny<<" "<<i<<"gg\n";
        if(vis[nx][ny]==0&&mp[nx][ny]=='x')dfs(nx,ny,cc);
    }
}
void gravity(){
    int i,j,x=1;
    vector<pair<int,int>> cluster;
    memset(vis,0,sizeof(vis));
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(mp[i][j]=='x'&&vis[i][j]==0){
                //cout<<i<<" "<<j<<"x\n";
                cluster.push_back({i,j});
                dfs(i,j,x);
                x++;
            }
        }
    }
    /*for(i=r-1;i>=0;i--){
        for(j=0;j<c;j++){
            cout<<vis[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";*/
    if(cluster.size()>1){
        for(i=0;i<cluster.size();i++){
            if(cluster[i].first==0)continue;
            vector<pair<int,int>> floor;
            int height=cluster[i].first;
            int vval=vis[height][cluster[i].second];
            for(j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    if(vis[j][k]==vval){
                        if(vis[j-1][k]==0)floor.push_back({j,k});
                    }
                }
            }
            //cout<<height<<" "<<vval<<"\n";
            while(height>0){
                for(j=0;j<r;j++){
                    for(int k=0;k<c;k++){
                        if(vis[j][k]==vval){swap(mp[j][k],mp[j-1][k]);swap(vis[j][k],vis[j-1][k]);}
                    }
                }
                height--;
                int ch=0;
                for(auto &j:floor){
                    //cout<<j.first<<" "<<j.second<<"vv\n";
                    j.first--;
                }
                for(auto &j:floor){
                    if(mp[j.first-1][j.second]=='x'){
                        ch=1;
                        break;
                    }
                }
                if(ch)break;
            }
        }
    }
    return;
}
int main(){
    cin>>r>>c;

    int i,j;
    for(i=r-1;i>=0;i--){
        for(j=0;j<c;j++){
            cin>>mp[i][j];
        }
    }
    int n;
    cin>>n;
    vector<int> stick;
    for(i=0;i<n;i++){
        int a;
        cin>>a;
        a--;
        if(i%2==0){
            for(j=0;j<c;j++){
                if(mp[a][j]=='x'){
                    mp[a][j]='.';
                    break;
                }
            }
        }
        else{
            for(j=c-1;j>=0;j--){
                if(mp[a][j]=='x'){
                    mp[a][j]='.';
                    break;
                }
            }
        }

        gravity();
    }
    for(i=r-1;i>=0;i--){
        for(j=0;j<c;j++){
            cout<<mp[i][j];
        }
        cout<<"\n";
    }
}