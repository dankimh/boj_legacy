#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<vector<int>> mp,rmp;
vector<int> nums;
stack<int> s;
vector<int> vis;
int num=0;
int opp(int node){
    return node%2?node+1:node-1;
}
void dfs(int node){
    vis[node]=1;
    for(auto &i:mp[node]){if(!vis[i])dfs(i);}
    s.push(node);
}
void scc(int node){
    nums[node]=num;
    for(auto &i:rmp[node])if(!nums[i])scc(i);
    return;
}
int main(){

    int n,m,i,j;
    cin>>n>>m;
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.assign(m*2+1,0);
    mp.resize(m*2+1);
    rmp.resize(m*2+1);
    vis.assign(m*2+1,0);

    vector<vector<int>> answer;
    for(i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        a=a<0?-(a*2)-1:a*2;
        b=b<0?-(b*2)-1:b*2;
        mp[opp(a)].push_back(b);
        mp[opp(b)].push_back(a);
        rmp[b].push_back(opp(a));
        rmp[a].push_back(opp(b));
    }
    for(i=1;i<=2*m;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(m*2+1,0);
    while(!s.empty()){
        int x=s.top();s.pop();
        if(!nums[x]){
            num++;
            scc(x);
        }
    }

    for(i=1;i<=m;i++){
        if(nums[i*2]==nums[i*2-1]){
            printf("OTL");
            exit(0);
        }
    }
    /*for(i=1;i<=n;i++){
        printf("%d %d\n",node[i*2-1],node[i*2]);
    }*/
    printf("^_^");
}