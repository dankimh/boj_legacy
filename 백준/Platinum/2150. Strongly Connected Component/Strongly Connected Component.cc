#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<vector<int>> mp,rmp;
vector<int> nums;
stack<pii> s;
vector<int> vis;
int num;
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
    int v,e;
    cin>>v>>e;
    nums.resize(v+1);
    mp.resize(v+1);
    rmp.resize(v+1);
    vis.assign(v+1,0);
    vector<vector<int>> answer;
    int i;
    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        rmp[b].push_back(a);
    }
    for(i=1;i<=v;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(v+1,0);
    while(!s.empty()){
        vector<int> ans;
        scc(s.top(),ans);
        while(!s.empty()&&vis[s.top().second]==1){
            s.pop();
        }
        sort(ans.begin(),ans.end());
        answer.push_back(ans);
    }
    sort(answer.begin(),answer.end());
    printf("%d\n",answer.size());
    for(auto &i:answer){
        for(auto &j:i)printf("%d ",j);
        printf("-1\n");
    }
}