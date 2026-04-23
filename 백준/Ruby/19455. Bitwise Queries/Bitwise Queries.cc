#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF=1e11;
constexpr ll all1=2147483647;
struct val{
    ll mx;
    ll mn;
    ll ands;
    ll ors;
};
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _lazy_and;
    vector<ll> _lazy_or;

    int _sz;
    void update_lazy(int st,int en, int node){
        _tree[node].mn=(_lazy_and[node]&_tree[node].mn)|_lazy_or[node];
        _tree[node].mx=(_lazy_and[node]&_tree[node].mx)|_lazy_or[node];
        _tree[node].ors=(_lazy_and[node]&_tree[node].ors)|_lazy_or[node];
        _tree[node].ands=(_lazy_and[node]&_tree[node].ands)|_lazy_or[node];
        if(st!=en){
            _lazy_or[node*2]=(_lazy_or[node*2]&_lazy_and[node])|_lazy_or[node];
            _lazy_and[node*2]=(_lazy_and[node*2]&_lazy_and[node]);
            _lazy_or[node*2+1]=(_lazy_or[node*2+1]&_lazy_and[node])|_lazy_or[node];
            _lazy_and[node*2+1]=(_lazy_and[node*2+1]&_lazy_and[node]);

        }
        _lazy_or[node]=0;
        _lazy_and[node]=all1;
        return;
    }
    val mer(val a,val b){
        return {max(a.mx,b.mx),min(a.mn,b.mn),a.ands&b.ands,a.ors|b.ors};
    }
    val init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            return this->_tree[node]={a[st],a[st],a[st],a[st]};
        }
        int mid=(st+en)/2;
        auto a1=init(st,mid,node*2,a);
        auto a2=init(mid+1,en,node*2+1,a);
        return this->_tree[node]=mer(a1,a2);
    }
public:
    lazySegtree(vector<ll>& other){
        this->_sz=other.size();
        this->_tree.resize(_sz*4);
        this->_lazy_or.resize(_sz*4,0);
        this->_lazy_and.resize(_sz*4,all1);
        init(0,_sz-1,1,other);
    }
    ll mx(int st,int en, int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return -INF;
        if(l<=st&&en<=r)return _tree[node].mx;
        int mid=(st+en)/2;
        return max(mx(st,mid,node*2,l,r),mx(mid+1,en,node*2+1,l,r));
    }
    ll mn(int st,int en, int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return INF;
        if(l<=st&&en<=r)return _tree[node].mn;
        int mid=(st+en)/2;
        return min(mn(st,mid,node*2,l,r),mn(mid+1,en,node*2+1,l,r));
    }
    val update_or(int st,int en,int node,int l,int r,ll x){
        update_lazy(st,en,node);
        if(st==en)assert(_tree[node].ors==_tree[node].ands);
        if(l>en||r<st)return _tree[node];
        ll u=(x&_tree[node].ors&~_tree[node].ands);
        if(l<=st&&en<=r&&u==0){
            _lazy_or[node]|=x;
            update_lazy(st,en,node);
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_or(st,mid,node*2,l,r,x),update_or(mid+1,en,node*2+1,l,r,x));
    }
    val update_and(int st,int en,int node,int l,int r,ll x){
        update_lazy(st,en,node);
        if(st==en)assert(_tree[node].ors==_tree[node].ands);
        if(l>en||r<st)return _tree[node];
        ll u=(~x&_tree[node].ors&~_tree[node].ands);
        if(l<=st&&en<=r&&u==0){
            _lazy_and[node]&=x;
            _lazy_or[node]&=x;
            update_lazy(st,en,node);
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_and(st,mid,node*2,l,r,x),update_and(mid+1,en,node*2+1,l,r,x));
    }
    vector<val>& tree(){
        return _tree;
    }
};
void solve(){
    int n,q;
    cin>>n;
    vector<ll> a;
    a.resize(n);
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    lazySegtree seg(a);
    cin>>q;
    for(i=0;i<q;i++){
        char inst;
        cin>>inst;
        if(inst=='&'){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_and(0,n-1,1,x-1,y-1,z);
        }
        if(inst=='|'){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_or(0,n-1,1,x-1,y-1,z);
        }
        if(inst=='?'){
            ll x,y,z;
            cin>>x>>y;
            cout<<seg.mn(0,n-1,1,x-1,y-1)<<"\n";

        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
}