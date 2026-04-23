#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> mem;
vector<int> rnk;
int f(int node,int r){
    //cout<<node<<"x\n";
    if(mem[node])return mem[node];//?
    rnk[node]=r;
    if(mp[node].size()==0)return mem[node]=1;
    else{
        int ans=0;
        for(auto &i:mp[node])if(rnk[i]==0)ans+=f(i,r+1);
        return mem[node]=ans+1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,r,q;
    cin>>n>>r>>q;
    mp.resize(n+1);
    mem.resize(n+1,0);
    rnk.resize(n+1,0);
    int i;
    for(i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    f(r,1);
    for(i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<mem[a]<<"\n";
    }
}