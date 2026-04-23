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
    int sz=n+m;
    vector<string> museum(n);
    for(i=0;i<n;i++)cin>>museum[i];
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.assign(sz*2+1,0);
    mp.resize(sz*2+1);
    rmp.resize(sz*2+1);
    vis.assign(sz*2+1,0);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int x=i+1+m,y=j+1;
            if(museum[i][j]=='*'){
                mp[x*2-1].push_back(y*2);
                mp[y*2-1].push_back(x*2);
                mp[x*2].push_back(y*2-1);
                mp[y*2].push_back(x*2-1);
                rmp[x*2-1].push_back(y*2);
                rmp[y*2-1].push_back(x*2);
                rmp[x*2].push_back(y*2-1);
                rmp[y*2].push_back(x*2-1);
            }
            else if(museum[i][j]=='#'){
                mp[x*2].push_back(y*2);
                mp[y*2].push_back(x*2);
                mp[x*2-1].push_back(y*2-1);
                mp[y*2-1].push_back(x*2-1);
                rmp[x*2].push_back(y*2);
                rmp[y*2].push_back(x*2);
                rmp[x*2-1].push_back(y*2-1);
                rmp[y*2-1].push_back(x*2-1);
            }
        }
    }


    vector<vector<int>> answer;
    for(i=1;i<=2*sz;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(sz*2+1,0);
    while(!s.empty()){
        int x=s.top();s.pop();
        if(!nums[x]){
            num++;
            scc(x);
        }
    }
    for(i=1;i<=sz;i++){
        if(nums[i*2]==nums[i*2-1]){
            printf("0");
            exit(0);
        }
    }

    printf("1");
}