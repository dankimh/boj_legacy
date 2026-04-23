#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF=1e11;
constexpr ll all1=2147483647;
class lazySegtree{
private:
    vector<ll> _tree;
    vector<ll> _lazy;

    int _sz;
    void update_lazy(int st,int en, int node){
        if(_lazy[node]!=0){
            _tree[node]^=_lazy[node];
            if(st!=en){
                _lazy[node*2]^=_lazy[node];
                _lazy[node*2+1]^=_lazy[node];
            }
        }
        _lazy[node]=0;
        return;
    }
    ll init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            return this->_tree[node]=a[st];
        }
        int mid=(st+en)/2;
        auto a1=init(st,mid,node*2,a);
        auto a2=init(mid+1,en,node*2+1,a);
        return this->_tree[node]=a1^a2;
    }
public:
    lazySegtree(vector<ll>& other){
        this->_sz=other.size();
        this->_tree.resize(_sz*4);
        this->_lazy.resize(_sz*4,0);
        init(0,_sz-1,1,other);
    }
    ll val(int st,int en,int node,int idx){
        update_lazy(st,en,node);
        if(idx>en||idx<st)return 0;
        if(st==idx&&en==idx)return _tree[node];
        int mid=(st+en)/2;
        return val(st,mid,node*2,idx)+val(mid+1,en,node*2+1,idx);
    }
    ll update(int st,int en,int node,int l,int r,ll x){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r){
            _lazy[node]^=x;
            update_lazy(st,en,node);
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=(update(st,mid,node*2,l,r,x)^update(mid+1,en,node*2+1,l,r,x));
    }
    vector<ll>& tree(){
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
        ll inst;
        cin>>inst;
        if(inst==1){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update(0,n-1,1,x,y,z);
        }
        if(inst==2){
            ll x,y,z;
            cin>>x;
            cout<<seg.val(0,n-1,1,x)<<"\n";
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