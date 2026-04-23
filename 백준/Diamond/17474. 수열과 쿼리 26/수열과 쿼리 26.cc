#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct val{
    ll sum=0;
    ll mx=-1;
    ll smx=-1;
    ll mxcnt=0;
};
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _a;
    int _sz;
    void update_lazy(int st,int en, int node){
        if(st!=en){
            for(int i=node*2;i<node*2+2;i++){
                if(_tree[node].mx<_tree[i].mx){
                    this->_tree[i].sum-=(_tree[i].mx-_tree[node].mx)*_tree[i].mxcnt;
                    this->_tree[i].mx=_tree[node].mx;
                }
            }
        }
    }
    val mer(val a,val b){
        if(a.mx==b.mx){
            return {a.sum+b.sum,a.mx,max(a.smx,b.smx),a.mxcnt+b.mxcnt};
        }
        if(a.mx>b.mx)swap(a,b);
        return {a.sum+b.sum,b.mx,max(a.mx,b.smx),b.mxcnt};
    }
public:
    lazySegtree(int n,vector<ll>& other){
        this->_sz=n;
        this->_tree.resize(n*4);
        this->_a.resize(n+1,0);
        copy(other.begin(),other.end(),this->_a.begin());
    }
    val init(int st, int en, int node){
        if(st==en){
            this->_tree[node].sum=_a[st];
            this->_tree[node].mx=_a[st];
            this->_tree[node].mxcnt++;
            return this->_tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(init(st,mid,node*2),init(mid+1,en,node*2+1));
    }
    ll sum(int st,int en, int node, int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node].sum;
        int mid=(st+en)/2;
        return sum(st,mid,node*2,l,r)+sum(mid+1,en,node*2+1,l,r);
    }
    val update_tree(int st,int en,int node,int l,int r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st||_tree[node].mx<=val)return _tree[node];
        if(l<=st&&en<=r&&_tree[node].smx<val){
            this->_tree[node].sum-=(_tree[node].mx-val)*_tree[node].mxcnt;
            this->_tree[node].mx=val;
            update_lazy(st,en,node);
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_tree(st,mid,node*2,l,r,val),update_tree(mid+1,en,node*2+1,l,r,val));
    }
    ll maxval(int st,int en,int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return -1;
        if(l<=st&&en<=r)return _tree[node].mx;
        int mid=(st+en)/2;
        return max(maxval(st,mid,node*2,l,r),maxval(mid+1,en,node*2+1,l,r));
    }
    vector<val>& tree(){
        return _tree;
    }
};
int main(){
    int n;
    scanf("%d",&n);
    vector<ll> a(n);
    int i;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    lazySegtree seg(n,a);
    seg.init(0,n-1,1);
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int inst;
        scanf("%d",&inst);
        if(inst==1){
            ll x,y,z;
            scanf("%lld %lld %lld",&x,&y,&z);
            seg.update_tree(0,n-1,1,x-1,y-1,z);
        }
        if(inst==2){
            ll x,y;
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",seg.maxval(0,n-1,1,x-1,y-1));
        }
        if(inst==3){
            ll x,y;
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",seg.sum(0,n-1,1,x-1,y-1));
        }
    }
}