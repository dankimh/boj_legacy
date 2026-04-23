#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<vector<int>> mp,rmp;
vector<int> nums;
stack<int> s;
vector<int> vis;
int num=0;
void dfs(int node){
    vis[node]=1;
    for(auto &i:mp[node])if(!vis[i])dfs(i);
    s.push(node);
}
void scc(int node){
    nums[node]=num;
    for(auto &i:rmp[node])if(!nums[i])scc(i);
    return;
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        int m,i,j;

        cin>>m;
        mp.clear();
        rmp.clear();
        nums.clear();
        vis.clear();
        mp.resize(n+1);
        rmp.resize(n+1);
        nums.resize(n+1,0);
        vis.resize(n+1,0);
        num=0;
        for(i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            mp[a].push_back(b);
            rmp[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(!vis[i])dfs(i);
        }
        while(!s.empty()){
            int x=s.top();s.pop();
            if(!nums[x]){
                num++;
                scc(x);
            }
        }
        /*for(i=1;i<=n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"x\n";*/
        int nmpsz=nums[max_element(nums.begin(),nums.end())-nums.begin()];
        //cout<<nmpsz<<"y\n";
        vector<vector<int>> ans(nmpsz);
        for(i=1;i<=n;i++){
            ans[nums[i]-1].push_back(i);
        }
        vector<vector<int>> nmp(nmpsz);
        for(i=1;i<=n;i++){
            for(j=0;j<mp[i].size();j++){
                if(nums[i]==nums[mp[i][j]])continue;
                nmp[nums[i]-1].push_back(nums[mp[i][j]]-1);
            }
        }
        for(i=0;i<nmp.size();i++){
            sort(nmp[i].begin(),nmp[i].end());
            nmp[i].erase(unique(nmp[i].begin(),nmp[i].end()),nmp[i].end());
        }
        vector<vector<int>> rnmp(nmpsz);
        for(i=0;i<nmp.size();i++){
            for(j=0;j<nmp[i].size();j++){
                rnmp[nmp[i][j]].push_back(i);
            }
        }
        vector<int> c;
        for(i=0;i<nmp.size();i++){
            if(nmp[i].size()==0)c.push_back(i);
        }
        vector<int> ret;
        for(i=0;i<c.size();i++){
            for(j=0;j<ans[c[i]].size();j++){
                ret.push_back(ans[c[i]][j]);
            }
        }
        sort(ret.begin(),ret.end());
        for(auto &i:ret)cout<<i<<" ";
        cout<<"\n";
    }
}
