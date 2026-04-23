#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<vector<int>> tree;
vector<int> depth;
vector<vector<int>> parent;
void make_tree(int now,int par,int dep){
    if(depth[now]!=0)return;
    parent[now][0]=par;
    for(int i=0;i<20;i++){
        parent[now][i+1]=(parent[parent[now][i]][i]);
    }
    depth[now]=dep;
    for(int i=0;i<mp[now].size();i++){
        tree[i].push_back(mp[now][i]);
        make_tree(mp[now][i],now,dep+1);
    }
    return;
}
int lca(int a,int b){
    if(a==1||b==1)return 1;

    int x=a,y=b;
    if(depth[x]<depth[y])swap(x,y);

    if(depth[x]!=depth[y]){
        for(int i=20;i>=0;i--){
            if(depth[parent[x][i]]>=depth[y]){
                x=parent[x][i];
            }
        }
    }
    int ans=x;
    if(x!=y){
        for(int i=20;i>=0;i--){
            if(parent[x][i]!=parent[y][i]){
                x=parent[x][i];
                y=parent[y][i];
            }
            ans=parent[x][i];
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    mp.resize(n+1);
    tree.resize(n+1);
    depth.resize(n+1,0);
    parent.resize(n+1,vector<int>(30,0));
    int i;
    for(i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    make_tree(1,0,1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
}