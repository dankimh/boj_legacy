#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct val{
    ll sum=0;
    ll mx;
    ll mn;
};
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _ischangeadd;
    vector<ll> _ischangesq;
    int _sz;
    void update_lazy(int st,int en, int node){
        if(_ischangeadd[node]==0&&_ischangesq[node]==0)return;
        if(_ischangesq[node]!=0){
            _tree[node].sum=_ischangesq[node]*(en-st+1);
            _tree[node].mx=_tree[node].mn=_ischangesq[node];
            _tree[node].sum+=_ischangeadd[node]*(en-st+1);
            _tree[node].mx+=_ischangeadd[node];
            _tree[node].mn+=_ischangeadd[node];
            if(st!=en){
                _ischangesq[node*2]=_ischangesq[node*2+1]=_ischangesq[node];
                _ischangeadd[node*2]=_ischangeadd[node*2+1]=_ischangeadd[node];
            }
        }
        else{
            _tree[node].sum+=_ischangeadd[node]*(en-st+1);
            _tree[node].mx+=_ischangeadd[node];
            _tree[node].mn+=_ischangeadd[node];
            if(st!=en){
                _ischangeadd[node*2]+=_ischangeadd[node];
                _ischangeadd[node*2+1]+=_ischangeadd[node];
            }
        }
        _ischangesq[node]=_ischangeadd[node]=0;
        return;
    }
    val mer(val a,val b){
        return {a.sum+b.sum,max(a.mx,b.mx),min(a.mn,b.mn)};
    }
    val init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            return this->_tree[node]={a[st],a[st],a[st]};
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
        this->_ischangeadd.resize(_sz*4,0);
        this->_ischangesq.resize(_sz*4,0);
        init(0,_sz-1,1,other);
    }
    ll sum(int st,int en, int node, int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node].sum;
        int mid=(st+en)/2;
        return sum(st,mid,node*2,l,r)+sum(mid+1,en,node*2+1,l,r);
    }
    val update_sq(int st,int en,int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return _tree[node];
        if(l<=st&&en<=r&&((ll)sqrt(_tree[node].mx)==(ll)sqrt(_tree[node].mn))){
            _ischangesq[node]=(ll)sqrt(_tree[node].mx);
            //_ischangeadd[node]=0;
            /*this->_tree[node].sum=(en-st+1)*(ll)sqrt(_tree[node].mx);
            this->_tree[node].mn=this->_tree[node].mx=(ll)sqrt(_tree[node].mx);*/
            update_lazy(st,en,node);
            return this->_tree[node];
        }
        if(l<=st&&en<=r&&_tree[node].mn+1==_tree[node].mx){
            _ischangeadd[node]=-_tree[node].mx+(ll)sqrt(_tree[node].mx);
            update_lazy(st,en,node);
            return this->_tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_sq(st,mid,node*2,l,r),update_sq(mid+1,en,node*2+1,l,r));
    }
    val update_add(int st,int en,int node,int l,int r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st)return _tree[node];
        if(l<=st&&en<=r){
            _ischangeadd[node]+=val;
            update_lazy(st,en,node);
            return this->_tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_add(st,mid,node*2,l,r,val),update_add(mid+1,en,node*2+1,l,r,val));
    }
    vector<val>& tree(){
        return _tree;
    }
};
void solve(){
    int n,q;
    cin>>n>>q;

    vector<ll> a(n);
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    lazySegtree seg(a);

    for(i=0;i<q;i++){
        int inst;
        cin>>inst;
        if(inst==3){
            ll x,y;
            cin>>x>>y;
            cout<<seg.sum(0,n-1,1,x-1,y-1)<<"\n";
        }
        if(inst==2){
            ll x,y;
            cin>>x>>y;
            seg.update_sq(0,n-1,1,x-1,y-1);
        }
        if(inst==1){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_add(0,n-1,1,x-1,y-1,z);
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