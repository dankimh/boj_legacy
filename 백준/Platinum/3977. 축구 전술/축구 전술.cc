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
void MAIN(){
    int v,e;
    cin>>v>>e;

    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.resize(v);
    mp.resize(v);
    rmp.resize(v);
    vis.assign(v,0);

    vector<vector<int>> answer;
    int i,j;
    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        rmp[b].push_back(a);
    }
    for(i=0;i<v;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(v,0);
    while(!s.empty()){
        vector<int> ans;
        scc(s.top(),ans);
        while(!s.empty()&&vis[s.top().second]==1){
            s.pop();
        }
        answer.push_back(ans);
    }
    /*printf("%d\n",answer.size());
    for(auto &i:answer){
        for(auto &j:i)printf("%d ",j);
        printf("-1\n");
    }*/
    vector<int> node(v+1);
    for(int i=0; i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            node[answer[i][j]]=i;
        }
    }
    vector<vector<int>> nmp(answer.size());
    for(i=0;i<v;i++){
        for(j=0;j<mp[i].size();j++){
            if(node[i]==node[mp[i][j]])continue;
            nmp[node[i]].push_back(node[mp[i][j]]);
        }

    }
    for(i=0;i<nmp.size();i++){
        sort(nmp[i].begin(),nmp[i].end());
        nmp[i].erase(unique(nmp[i].begin(),nmp[i].end()),nmp[i].end());
    }

    vector<vector<int>> rnmp(answer.size());
    for(i=0;i<nmp.size();i++){
        for(j=0;j<nmp[i].size();j++){
            rnmp[nmp[i][j]].push_back(i);
        }
    }/*for(i=0;i<rnmp.size();i++){
        printf("%d - ",i);
        for(j=0;j<rnmp[i].size();j++){
            printf("%d ",rnmp[i][j]);
        }
        printf("\n");
    }*/
    int c=0;
    vector<int> ans;
    for(i=0;i<rnmp.size();i++){
        if(rnmp[i].size()==0){
            c++;
            for(auto &j:answer[i]){
                ans.push_back(j);
            }
        }
    }
    if(c!=1)printf("Confused\n\n");
    else{
        sort(ans.begin(),ans.end());
        for(auto &i:ans)printf("%d\n",i);
        printf("\n");
    }
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        MAIN();
    }
}
