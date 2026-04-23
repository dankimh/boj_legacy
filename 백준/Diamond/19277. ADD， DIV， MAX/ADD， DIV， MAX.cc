#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct val{
    ll mx;
    ll mn;
};
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _ischangeadd;
    vector<ll> _ischangef;
    int _sz;
    void update_lazy(int st,int en, int node){
        if(_ischangeadd[node]==0&&_ischangef[node]==-1)return;
        if(_ischangef[node]!=-1){
            _tree[node].mx=_tree[node].mn=(_ischangef[node]+_ischangeadd[node]);
            if(st!=en){
                _ischangef[node*2]=_ischangef[node*2+1]=_ischangef[node];
                _ischangeadd[node*2]=_ischangeadd[node*2+1]=_ischangeadd[node];
            }
        }
        else{
            _tree[node].mx+=_ischangeadd[node];
            _tree[node].mn+=_ischangeadd[node];
            if(st!=en){
                _ischangeadd[node*2]+=_ischangeadd[node];
                _ischangeadd[node*2+1]+=_ischangeadd[node];
            }
        }
        _ischangef[node]=-1;
        _ischangeadd[node]=0;
        return;
    }
    val mer(val a,val b){
        return {max(a.mx,b.mx),min(a.mn,b.mn)};
    }
    val init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            return this->_tree[node]={a[st],a[st]};
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
        this->_ischangef.resize(_sz*4,-1);
        init(0,_sz-1,1,other);
    }
    ll mx(int st,int en, int node, int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return -1;
        if(l<=st&&en<=r)return _tree[node].mx;
        int mid=(st+en)/2;
        return max(mx(st,mid,node*2,l,r),mx(mid+1,en,node*2+1,l,r));
    }
    val update_floor(int st,int en,int node,int l,int r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st)return _tree[node];
        if(l<=st&&en<=r&&(ll)(_tree[node].mx/val)==(ll)(_tree[node].mn/val)){
            _ischangef[node]=(ll)(_tree[node].mx/val);
            update_lazy(st,en,node);
            return this->_tree[node];
        }
        if(l<=st&&en<=r&&_tree[node].mn+1==_tree[node].mx){
            _ischangeadd[node]=((ll)(_tree[node].mx/val)-_tree[node].mx);
            update_lazy(st,en,node);
            return this->_tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_floor(st,mid,node*2,l,r,val),update_floor(mid+1,en,node*2+1,l,r,val));
    }
    val update_add(int st,int en,int node,int l,int r,ll val){
        //cout<<st<<" "<<en<<"add\n";
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
    /*for(auto &x:seg.tree()){
            cout<<x.mx<<" ";
        }
        cout<<"\n";*/

    for(i=0;i<q;i++){
        int inst;
        cin>>inst;
        if(inst==0){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_add(0,n-1,1,x,y,z);
        }
        if(inst==1){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_floor(0,n-1,1,x,y,z);
        }
        if(inst==2){
            ll x,y,z;
            cin>>x>>y>>z;
            cout<<seg.mx(0,n-1,1,x,y)<<"\n";
        }
       /* for(auto &x:seg.tree()){
            cout<<x.sum<<" ";
        }
        cout<<"\n";*/
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
}