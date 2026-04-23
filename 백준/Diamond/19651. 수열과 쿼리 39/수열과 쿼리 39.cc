#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF=1e10;
struct val{
    ll stcnt;
    ll stval;
    ll encnt;
    ll enval;
    ll mxcnt;
    ll len;
};
/*void print(val a){
        printf("(%lld,%lld,%lld,%lld,%lld,%lld)\n",a.stcnt,a.stval,a.encnt,a.enval,a.mxcnt,a.len);
    }*/
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _lazy;//y
    int _sz;
    void update_lazy(int st,int en, int node){
        if(_lazy[node]!=0){
            _tree[node].stval+=_lazy[node];
            _tree[node].enval+=_lazy[node];
            if(st!=en){
                _lazy[node*2]+=_lazy[node];
                _lazy[node*2+1]+=_lazy[node];
            }
        }
        _lazy[node]=0;
        return;
    }
    val mer(val a,val b){
        val ret={a.stcnt,a.stval,b.encnt,b.enval,0,a.len+b.len};
        ret.mxcnt=max(a.mxcnt,b.mxcnt);
        if(a.enval==b.stval){
            ret.mxcnt=max(ret.mxcnt,a.encnt+b.stcnt);
            if(a.encnt==a.len){
                ret.stcnt=a.stcnt+b.stcnt;
            }
            if(b.stcnt==b.len){
                ret.encnt=a.encnt+b.encnt;
            }
        }
        return ret;
    }
    val init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            return this->_tree[node]={1,a[st],1,a[st],1,1};
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
        this->_lazy.resize(_sz*4,0);
        init(0,_sz-1,1,other);
    }
    val mxlen(int st,int en, int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st||l>r)return {0,0,0,0,0,0};
        if(l<=st&&en<=r)return _tree[node];
        int mid=(st+en)/2;
        return mer(mxlen(st,mid,node*2,l,r),mxlen(mid+1,en,node*2+1,l,r));
    }
    val update(int st,int en,int node,int l,int r,ll x){
        //cout<<st<<" "<<en<<"add\n";
        update_lazy(st,en,node);
        if(l>en||r<st)return _tree[node];
        if(l<=st&&en<=r){
            _lazy[node]+=x;
            update_lazy(st,en,node);
            return this->_tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update(st,mid,node*2,l,r,x),update(mid+1,en,node*2+1,l,r,x));
    }
    vector<val>& tree(){
        return _tree;
    }
};
void solve(){
    int n,q;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n-1);
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(i>0)b[i-1]=a[i]-a[i-1];
    }
    lazySegtree seg(b);
    /*for(auto &x:seg.tree()){
            print(x);
        }
        cout<<"\n";*/
    cin>>q;
    for(i=0;i<q;i++){
        int inst;
        cin>>inst;
        if(inst==1){
            ll x,y,z,w;
            cin>>x>>y>>z>>w;
            if(1<x)seg.update(0,n-2,1,x-2,x-2,z);
            if(y<n)seg.update(0,n-2,1,y-1,y-1,-(z+(y-x)*w));
            seg.update(0,n-2,1,x-1,y-2,w);
        }
        if(inst==2){
            ll x,y,z;
            cin>>x>>y;
            cout<<seg.mxlen(0,n-2,1,x-1,y-2).mxcnt+1<<"\n";
        }
        /*for(auto &x:seg.tree()){
            print(x);
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
