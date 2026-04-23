#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
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
void ddfs(int node,vector<vector<int>> &nmp){
    if(!vis[node]){

        vis[node]=1;
        for(auto &i:nmp[node])ddfs(i,nmp);
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
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n,m,ss,t;
    cin>>n>>m>>ss>>t;

    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.resize(n+1);
    mp.resize(n+1);
    rmp.resize(n+1);
    vis.assign(n+1,0);

    vector<vector<int>> answer;
    vector<int> cost(n+1);
    int i,j;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        rmp[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(n+1,0);
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
    int anssiz=(int)answer.size();
    vector<int> node(n+1);
    for(int i=0; i<anssiz;i++){
        for(int j=0;j<answer[i].size();j++){
            node[answer[i][j]]=i;
        }
    }
    vector<vector<int>> nmp(anssiz);
    vector<ll> ncost(anssiz,0);
    for(i=1;i<=n;i++){
        for(j=0;j<mp[i].size();j++){
            if(node[i]==node[mp[i][j]])continue;
            nmp[node[i]].push_back(node[mp[i][j]]);
        }
        //printf("(%d - %d) ",i,node[i]);
        ncost[node[i]]++;
    }
    //printf("\n");
    for(i=0;i<nmp.size();i++){
        sort(nmp[i].begin(),nmp[i].end());
        nmp[i].erase(unique(nmp[i].begin(),nmp[i].end()),nmp[i].end());
    }
    vis.clear();
    vis.assign(anssiz,0);
    int startpoint=node[ss];
    //printf("st - %d\n",startpoint);
    ddfs(startpoint,nmp);
    for(i=0;i<anssiz;i++){
        if(vis[i]==0)ncost[i]=0;
        //printf("(%d - %d) ",i,ncost[i]);
    }
    //printf("\n");
    vector<vector<int>> rnmp(anssiz);
    vector<ll> ans=ncost;
    for(i=0;i<nmp.size();i++){
        //printf("%d - ",i);
        for(j=0;j<nmp[i].size();j++){
            rnmp[nmp[i][j]].push_back(i);
            //printf("%d ",nmp[i][j]);
        }
        //printf("\n");
    }
    for(i=0;i<rnmp.size();i++){

        ll mx=0;
        for(j=0;j<rnmp[i].size();j++){

            mx=max(mx,ans[rnmp[i][j]]);
        }
        ans[i]=mx+ans[i];

    }
    cout<<ans[node[t]];
    /*int c=0;
    for(i=0;i<rnmp.size();i++){
        if(rnmp[i].size()==0)c++;
    }
    printf("%d\n",c);*/
}