#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
#ifdef DEBUG
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG

#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
#define arrin(x,n) for(ll qwer=0;qwer<n;qwer++)cin>>x[qwer];
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF=1e18;
struct Segtree{
private:
    vector<ll> _tree;
    ll _sz;
    void init(int st,int en,int node,vector<ll>& a){
        if(st==en){
            _tree[node]=a[st];
            return;
        }
        int mid=(st+en)/2;
        init(st,mid,node*2,a);
        init(mid+1,en,node*2+1,a);
        _tree[node]=_tree[node*2]+_tree[node*2+1];
        return;
    }

public:
    Segtree(vector<ll>& other){
        _sz=other.size();
        _tree.resize(_sz*4);
        init(0,_sz-1,1,other);
    }

    ll update(int st,int en,int node,int loc,ll val){
        if(loc<st||en<loc)return _tree[node];
        if(st==en){
            return _tree[node]=val;
        }
        int mid=(st+en)/2;
        return _tree[node]=update(st,mid,node*2,loc,val)+update(mid+1,en,node*2+1,loc,val);
    }
    
    ll sum(int st,int en,int node,int l,int r){
        if(en<l||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node];
        int mid=(st+en)/2;
        return sum(st,mid,node*2,l,r)+sum(mid+1,en,node*2+1,l,r);
    }

};
void solve(){
    ll n,q;
    cin>>n>>q;
    ll i;
    vector<ll> a(n);
    arrin(a,n);
    Segtree seg(a);
    while(q--){
        ll x,y,a,b;
        
        cin>>x>>y>>a>>b;
        if(x>y)swap(x,y);
        cout<<seg.sum(0,n-1,1,x-1,y-1)<<"\n";
        seg.update(0,n-1,1,a-1,b);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
