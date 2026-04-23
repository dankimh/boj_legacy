#include<bits/stdc++.h>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("input.txt");ofs.open("output.txt");
#ifdef DEBUG
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG
#define A(X,Y,Z,W) if(X[Y[Z]]==0)W--;
#define B(X,Y,Z,W) if(X[Y[Z]]==0)W++;
using namespace std;
typedef long long ll;
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
void solve(){
    cin>>n;
    int i;
    vector<int> x(n+1);
    vector<int> a(n+1);
    for(i=1;i<=n;i++){
        cin>>x[i];
        a[i]=x[i];
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(i=1;i<=n;i++){
        a[i]=lower_bound(x.begin(),x.end(),a[i])-x.begin();
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}


