#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<vector<int>> mp,rmp;
vector<int> nums;
stack<pii> s;
vector<int> vis;
int num;
int opp(int node){
    return node%2?node+1:node-1;
}
void dfs(int node){
    if(!vis[node]){
        vis[node]=1;
        for(auto &i:mp[node])dfs(i);
        s.push({num,node});
        nums[node]=num;
        num++;
    }
}
void scc(pii p,vector<int> &ans){
    if(!vis[p.second]){
        vis[p.second]=1;
        ans.push_back(p.second);
        for(auto &i:rmp[p.second])scc({nums[i],i},ans);
        return;
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.resize(n*2+1);
    mp.resize(n*2+1);
    rmp.resize(n*2+1);
    vis.assign(n*2+1,0);

    vector<vector<int>> answer;
    int i,j;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a=a<0?-(a*2)-1:a*2;
        b=b<0?-(b*2)-1:b*2;
        mp[opp(a)].push_back(b);
        mp[opp(b)].push_back(a);
        rmp[b].push_back(opp(a));
        rmp[a].push_back(opp(b));
    }
    for(i=1;i<=2*n;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(n*2+1,0);
    while(!s.empty()){
        vector<int> ans;
        scc(s.top(),ans);
        while(!s.empty()&&vis[s.top().second]==1){
            s.pop();
        }
        answer.push_back(ans);
    }
    vector<int> node(2*n+1);
    for(int i=0; i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            node[answer[i][j]]=i;
        }
    }
    for(i=1;i<=n;i++){
        if(node[i*2]==node[i*2-1]){
            printf("0");
            exit(0);
        }
    }
    printf("1");
}