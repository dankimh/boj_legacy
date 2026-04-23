#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,i;
    cin>>n;
    vector<int> p(n+1,-1);
    vector<int> vis(n+1,0);
    for(i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[b]=a;
    }
    int a,b;
    cin>>a>>b;
    while(1){
        vis[a]=1;
        if(p[a]==-1)break;
        a=p[a];
    }
    while(1){
        if(vis[b]){
            break;
        }
        b=p[b];
    }
    cout<<b<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}