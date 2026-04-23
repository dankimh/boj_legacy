#include<bits/stdc++.h>
using namespace std;
#define A(X,Y,Z,W) if(X[Y[Z]]==0)W--;
#define B(X,Y,Z,W) if(X[Y[Z]]==0)W++;
typedef long long ll;
int mp[1010101];//mp[x]=x의 개수
int cnt[101010];//cnt[x]=x개인 수의 수(mp[a]=x인 a의 개수)
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
    int st=q[0].st,en=q[0].en,sz=0,mx=-1;
    for(i=st;i<=en;i++){
        cnt[mp[a[i]]]--;
        mp[a[i]]++;
        if(mx<mp[a[i]])mx=mp[a[i]];
        cnt[mp[a[i]]]++;
    }
    ans[q[0].idx]=mx;
    for(i=1;i<q.size();i++){
        while(st<q[i].st){
            cnt[mp[a[st]]]--;
            if(mp[a[st]]==mx&&cnt[mp[a[st]]]==0)mx--;
            mp[a[st]]--;
            cnt[mp[a[st]]]++;
            st++;
        }
        while(st>q[i].st){
            st--;
            if(mp[a[st]]!=0)cnt[mp[a[st]]]--;
            mp[a[st]]++;
            if(mx<mp[a[st]])mx=mp[a[st]];
            cnt[mp[a[st]]]++;
        }
        while(en<q[i].en){
            en++;
            if(mp[a[st]]!=0)cnt[mp[a[en]]]--;
            mp[a[en]]++;
            if(mx<mp[a[en]])mx=mp[a[en]];
            cnt[mp[a[en]]]++;
        }
        while(en>q[i].en){
            cnt[mp[a[en]]]--;
            if(mp[a[en]]==mx&&cnt[mp[a[en]]]==0)mx--;
            mp[a[en]]--;
            cnt[mp[a[en]]]++;
            en--;
        }
        ans[q[i].idx]=mx;
    }
    for(auto &j:ans)cout<<j<<"\n";
}