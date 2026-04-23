#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> rnk;
vector<int> val;
vector<int> chk;
vector<int> answer;
pair<int,int> f(int node,int r){
    //cout<<node<<"x\n";
    rnk[node]=r;
    if(mp[node].size()==0){
        return {val[node],0};
    }
    else{
        int in=val[node],out=0;
        for(auto &i:mp[node])if(rnk[i]==0){
            auto ans=f(i,r+1);
            in+=ans.second;
            if(ans.first>ans.second){
                out+=ans.first;
                chk[i]=1;
            }
            else{
                out+=ans.second;
                chk[i]=0;
            }
        }
        return {in,out};
    }
}
void track(int node,int st){
    //cout<<node<<"y\n";
    rnk[node]=1;
    if(st){
        answer.push_back(node);
        for(auto &i:mp[node]){
            if(!rnk[i])track(i,0);
        }
    }
    else{
        for(auto &i:mp[node]){
            if(!rnk[i])track(i,chk[i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    mp.resize(n+1);
    rnk.resize(n+1,0);
    val.resize(n+1,0);
    chk.resize(n+1,-1);
    int i;
    for(i=0;i<n;i++)cin>>val[i+1];
    for(i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    auto ans=f(1,1);
    if(ans.first>ans.second)chk[1]=1;
    else chk[1]=0;
    cout<<max(ans.first,ans.second)<<"\n";
    rnk.clear();
    rnk.resize(n+1,0);
    track(1,chk[1]);
    sort(answer.begin(),answer.end());
    for(auto &i:answer)cout<<i<<" ";
}