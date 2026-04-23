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
    int n,k;
    cin>>n>>k;
    mp.resize(n);
    ch.resize(n);
    match.resize(n);
    fill(match.begin(),match.end(),-1);
    int i,j;
    for(i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        mp[a-1].push_back(b-1);
    }
    
    int cnt=0;
    for(i=0;i<n;i++){
        fill(ch.begin(),ch.end(),false);
        if(dfs(i))cnt++;
    }
    /*for(i=0;i<n;i++){
        cout<<(match[i])%n+1<<" "<<i+1<<"n\n";
    }*/
    cout<<cnt;
}