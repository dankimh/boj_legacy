#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<vector<int>> mp,rmp;
vector<int> nums;
stack<int> s;
vector<int> vis;
int num=0;
int f(int a){
    return a=a<0?-(a*2)-1:a*2;
}
void add(int a,int b){
    mp[a].push_back(b);
    rmp[b].push_back(a);
}
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
void MAIN(int n,int m){

    int i,j;
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.assign(n*2+1,0);
    mp.resize(n*2+1);
    rmp.resize(n*2+1);
    vis.assign(n*2+1,0);

    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a=f(a);b=f(b);
        add(opp(a),b);
        add(opp(b),a);
    }


    vector<vector<int>> answer;
    for(i=1;i<=2*n;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(n*2+1,0);
    while(!s.empty()){
        int x=s.top();s.pop();
        if(!nums[x]){
            num++;
            scc(x);
        }
    }
    for(i=1;i<=n;i++){
        if(nums[i*2]==nums[i*2-1]){
            printf("0\n");
            return;
        }
    }

    printf("1\n");
}
int main(){
    int n,m;
    while(cin>>n>>m){
        MAIN(n,m);
    }
}