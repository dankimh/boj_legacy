#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<vector<int>> mp,rmp;
vector<int> nums;
stack<pii> s;
vector<int> vis;
int num;
    bool cmp(pii a,pii b){
        if(abs(a.first)==abs(b.first))return abs(a.second)<abs(b.second);
        return abs(a.first)<abs(b.first);
    }
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

    int n,m,i,j;
    cin>>n>>m;
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.resize(m*2+1);
    mp.resize(m*2+1);
    rmp.resize(m*2+1);
    vis.assign(m*2+1,0);

    vector<int> light(n+1);
    vector<vector<int>> sw(n+1);
    for(i=1;i<=n;i++){
        cin>>light[i];
    }
    vector<vector<int>> answer;
    for(i=0;i<m;i++){
        int k;
        cin>>k;
        for(j=0;j<k;j++){
            int a;
            cin>>a;
            sw[a].push_back(i+1);
        }
    }
    for(i=1;i<=n;i++){
        int fi=sw[i][0],se=sw[i][1];
        if(light[i]==1){
            mp[fi*2].push_back(se*2);
            mp[se*2].push_back(fi*2);
            rmp[fi*2].push_back(se*2);
            rmp[se*2].push_back(fi*2);
            mp[fi*2-1].push_back(se*2-1);
            mp[se*2-1].push_back(fi*2-1);
            rmp[fi*2-1].push_back(se*2-1);
            rmp[se*2-1].push_back(fi*2-1);
        }
        else if(light[i]==0){
            mp[fi*2].push_back(se*2-1);
            mp[se*2].push_back(fi*2-1);
            rmp[fi*2-1].push_back(se*2);
            rmp[se*2-1].push_back(fi*2);
            mp[fi*2-1].push_back(se*2);
            mp[se*2-1].push_back(fi*2);
            rmp[fi*2].push_back(se*2-1);
            rmp[se*2].push_back(fi*2-1);
        }
    }
    for(i=1;i<=2*m;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(m*2+1,0);
    while(!s.empty()){
        vector<int> ans;
        scc(s.top(),ans);
        while(!s.empty()&&vis[s.top().second]==1){
            s.pop();
        }
        answer.push_back(ans);
    }
    vector<int> node(2*m+1);
    for(int i=0; i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            node[answer[i][j]]=i;
        }
    }
    for(i=1;i<=m;i++){
        if(node[i*2]==node[i*2-1]){
            printf("0");
            exit(0);
        }
    }
    /*for(i=1;i<=n;i++){
        printf("%d %d\n",node[i*2-1],node[i*2]);
    }*/
    printf("1");
}