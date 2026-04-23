#include<bits/stdc++.h>
using namespace std;
int n,ans;
pair<int,int> mp[123][123],pipe[123][123];
int bfs(int start){
    vector<int> vis(123,0);
    vector<int> path;
    queue<int> q;
    int i,now;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        now=q.front();
        //cout<<now<<"\n";
        if(now=='Z')break;
        q.pop();
        for(i=0;i<123;i++){
            if(vis[i]==0&&mp[now][i].first<mp[now][i].second){
                vis[i]=now;
                q.push(i);
            }
        }
    }
    if(now!='Z')return 0;
    char a='Z';
    path.push_back(a);
    while(a!='A'){
        a=vis[a];
        //cout<<a<<"\n";
        path.push_back(a);

    }
    /*for(i=path.size()-1;i>=0;i--){
        printf("%c-",path[i]);
    }
    cout<<"\n";*/
    int mn=100000000;
    for(i=path.size()-2;i>=0;i--){
        int now=path[i];
        int bef=path[i+1];
        int x=mp[bef][now].second-mp[bef][now].first;
        if(mn>x)mn=x;
    }
    ans+=mn;
    for(i=path.size()-2;i>=0;i--){
        int now=path[i];
        int bef=path[i+1];
        mp[bef][now].first+=mn;
        mp[now][bef].first-=mn;
    }
    return 1;
}
int main(){
    int i,j;
    cin>>n;
    for(i=0;i<123;i++){
        for(j=0;j<123;j++){
            mp[i][j]={0,0};
        }
    }
    for(i=0;i<n;i++){
        char a,b;
        int c;
        cin>>a>>b>>c;
        if(a==b)continue;
        mp[a][b].second+=c;
        mp[b][a].second+=c;
    }
    for(i=0;i<123;i++){
        for(j=0;j<123;j++){
            if(mp[i][j].second==0)mp[i][j].second=-100000000;
        }
    }
    while(1){
        int ex=bfs('A');
        if(ex==0)break;
        //cout<<ans<<"\n";
    }
    cout<<ans;
}