#include<bits/stdc++.h>
using namespace std;
vector<int> parent(200000);
vector<int> r(200000);
map<string,int> change;
int fi(int u){
    if(u==parent[u])return u;
    return parent[u]=fi(parent[u]);
}
void uni(int u,int v){
    u=fi(u);
    v=fi(v);
    if(u==v)return;
    parent[v]=u;
    r[u]+=r[v];
    return;
}
void solve(){
    int f;
    cin>>f;
    for(int i=0;i<=2*f;i++){
        parent[i]=i;
        r[i]=1;
    }
    int i;
    int name=0;
    for(i=0;i<f;i++){
        string a,b;

        cin>>a;
        cin>>b;
        if(change.find(a)==change.end()){
            change[a]=name++;
        }
        if(change.find(b)==change.end()){
            change[b]=name++;
        }
        uni(change[a],change[b]);
        cout<<r[fi(change[a])]<<"\n";
    }
}
int main(){
     ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}