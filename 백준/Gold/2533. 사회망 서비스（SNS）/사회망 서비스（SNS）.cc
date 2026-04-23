#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> mem;
vector<int> rnk;
int f(int node,int r){
    //cout<<node<<"x\n";
    if(mem[node])return mem[node];//?
    rnk[node]=r;
    if(mp[node].size()==0)return mem[node]=0;
    else{
        int ans=0,siz=0;
        for(auto &i:mp[node])if(rnk[i]==0){ans+=f(i,r+1);siz++;}
        //cout<<node<<" "<<ans<<"\n";
        if(ans!=siz){
            return mem[node]=1;
        }
        else return mem[node]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
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
    f(1,1);
    int odd=0,even=0,ans=0;
    for(i=1;i<=n;i++){
        ans+=mem[i];
    }
    cout<<ans;
}