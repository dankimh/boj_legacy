#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    vector<int> p(n+1,0);
    vector<vector<int>> mp(n+1);
    for(i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    p[1]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto &i:mp[now]){
            if(p[i]==0){
                p[i]=now;
                q.push(i);
            }
        }
    }
    for(i=2;i<=n;i++)cout<<p[i]<<"\n";

}
