#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> ch;//visited
vector<int> match;//matched node(right->left)
bool dfs(int x){
    for(int i=0;i<mp[x].size();i++){
        int now=mp[x][i];
        if(ch[now])continue;
        ch[now]=true;
        if(match[now]==-1||dfs(match[now])){
            match[now]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    mp.resize(n);
    ch.resize(m);
    match.resize(m);
    fill(match.begin(),match.end(),-1);
    int i,j;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        for(j=0;j<x;j++){
            int xx;
            cin>>xx;
            mp[i].push_back(xx-1);
        }
    }
    int cnt=0;
    for(i=0;i<n;i++){
        fill(ch.begin(),ch.end(),false);
        if(dfs(i))cnt++;
    }
    cout<<cnt;
}