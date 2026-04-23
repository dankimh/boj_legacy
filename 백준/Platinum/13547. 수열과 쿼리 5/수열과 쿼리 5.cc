#include<bits/stdc++.h>
using namespace std;
#define A(X,Y,Z,W) if(X[Y[Z]]==0)W--;
#define B(X,Y,Z,W) if(X[Y[Z]]==0)W++;
int mp[1010101];
int n;
struct Node{
    int idx,st,en;
};
bool cmp(Node& a,Node& b){
    if((a.st/(int)sqrt(n))!=(b.st/(int)sqrt(n)))return (a.st/(int)sqrt(n))<(b.st/(int)sqrt(n));
    else{
        return a.en<b.en;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int i;
    vector<int> a(n+1);
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<Node> q(m);
    for(i=0;i<m;i++){
        cin>>q[i].st>>q[i].en;
        q[i].idx=i;
    }
    sort(q.begin(),q.end(),cmp);
    vector<int> ans(m,0);
    int st=q[0].st,en=q[0].en,sz=0;
    for(i=st;i<=en;i++){
        B(mp,a,i,sz);
        mp[a[i]]++;
    }
    ans[q[0].idx]=sz;
    for(i=1;i<q.size();i++){
        while(st<q[i].st){mp[a[st]]--;A(mp,a,st,sz);st++;}
        while(st>q[i].st){st--;B(mp,a,st,sz);mp[a[st]]++;}
        while(en<q[i].en){en++;B(mp,a,en,sz);mp[a[en]]++;}
        while(en>q[i].en){mp[a[en]]--;A(mp,a,en,sz);en--;}
        ans[q[i].idx]=sz;
    }
    for(auto &j:ans)cout<<j<<"\n";
}