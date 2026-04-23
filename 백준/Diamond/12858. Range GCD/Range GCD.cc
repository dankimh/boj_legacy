#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct val{
    ll fval;
    ll rest_gcd;
};
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _lazy;
    int _sz;
    void update_lazy(int st,int en, int node){
        if(!_lazy[node])return;
        _tree[node].fval+=_lazy[node];
        if(st!=en){
            _lazy[node*2]+=_lazy[node];
            _lazy[node*2+1]+=_lazy[node];
        }
        _lazy[node]=0;
        return;
    }
    val mer(val a,val b){
        return {a.fval,gcd(a.rest_gcd,gcd(b.fval,b.rest_gcd))};
    }
    void init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            this->_tree[node]={a[st],0};
            return;
        }
        int mid=(st+en)/2;
        init(st,mid,node*2,a);
        init(mid+1,en,node*2+1,a);
        this->_tree[node]=mer(_tree[node*2],_tree[node*2+1]);
        return;
    }
public:
    lazySegtree(vector<ll>& other){
        this->_sz=other.size();
        this->_tree.resize(_sz*4);
        this->_lazy.resize(_sz*4,0);
        init(0,_sz-1,1,other);
    }
    void update(int st,int en, int node, int l,int r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st)return;
        if(l<=st&&en<=r){
            _lazy[node]+=val;
            update_lazy(st,en,node);
            return;
        }
        int mid=(st+en)/2;
        update(st,mid,node*2,l,r,val);
        update(mid+1,en,node*2+1,l,r,val);
        this->_tree[node]=mer(_tree[node*2],_tree[node*2+1]);
        return;
    }
    ll find_gcd(int st,int en,int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r){
            return gcd(_tree[node].fval,_tree[node].rest_gcd);
        }
        int mid=(st+en)/2;
        return gcd(find_gcd(st,mid,node*2,l,r),find_gcd(mid+1,en,node*2+1,l,r));
    }
    vector<val>& tree(){
        return _tree;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n);
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    lazySegtree seg(a);
    int m;
    cin>>m;
    for(i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==0){;
            cout<<seg.find_gcd(0,n-1,1,y-1,z-1)<<"\n";
        }
        else{
            seg.update(0,n-1,1,y-1,z-1,x);
        }
    }
}