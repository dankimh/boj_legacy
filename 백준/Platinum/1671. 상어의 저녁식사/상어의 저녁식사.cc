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
bool big(vector<int> a, vector<int> b){
    bool ch=true;
    int x=0;
    for(int i=0;i<3;i++){
        if(a[i]<b[i]){
            ch=false;
            break;
        }
        else if(a[i]==b[i]){
            x++;
        }
    }
    if(x==3)return false;
    return ch;
}
bool same(vector<int> a, vector<int> b){
    bool ch=true;
    for(int i=0;i<3;i++){
        if(a[i]!=b[i]){
            ch=false;
            break;
        }
    }
    return ch;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> status(n,vector<int>(3));
    mp.resize(2*n);
    ch.resize(n);
    match.resize(n);
    fill(match.begin(),match.end(),-1);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<3;j++)cin>>status[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(big(status[i],status[j])){
                mp[i].push_back(j);
                mp[i+n].push_back(j);
            }
            else if(same(status[i],status[j])){
                if(i>j){
                    mp[i].push_back(j);
                    mp[i+n].push_back(j);
                }
                else{
                    mp[j].push_back(i);
                    mp[j+n].push_back(i);
                }
            }
        }
    }
    /*for(i=0;i<n;i++){
        cout<<i<<"\n";
        for(auto &x:mp[i])cout<<x<<"x\n";
    }*/
    int cnt=0;
    for(i=0;i<2*n;i++){
        fill(ch.begin(),ch.end(),false);
        if(dfs(i))cnt++;
    }
    cout<<n-cnt;
}