#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class SegTree{
private:
    vector<ll> _tree;
    vector<ll> _lazy;
    ll _sz;
    void update_lazy(int st,int en,int node){
        if(!_lazy[node])return;
        _tree[node]=(en-st+1)-_tree[node];
        if(st!=en){
            _lazy[node*2]^=_lazy[node];
            _lazy[node*2+1]^=_lazy[node];
        }
        _lazy[node]=0;
    }
public:
    SegTree(ll n){
        _sz=n;
        _tree.resize(_sz*4,0);
        _lazy.resize(_sz*4,0);
    }
    void update(int st,int en,int node,int l,int r){
        //cout<<st<<" "<<en<<"d\n";
        update_lazy(st,en,node);
        if(l>en||r<st)return;
        if(l<=st&&en<=r){
            _lazy[node]^=1;
            update_lazy(st,en,node);
            return;
        }
        int mid=(st+en)/2;
        update(st,mid,node*2,l,r);
        update(mid+1,en,node*2+1,l,r);
        _tree[node]=_tree[node*2]+_tree[node*2+1];
        return;
    }
    ll cnt(int st,int en,int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r){
            return _tree[node];
        }
        int mid=(st+en)/2;
        return cnt(st,mid,node*2,l,r)+cnt(mid+1,en,node*2+1,l,r);
    }
    vector<ll>& tree(){
        return _tree;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    SegTree seg(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            seg.update(0,n-1,1,b-1,c-1);
        }
        else{
            cout<<seg.cnt(0,n-1,1,b-1,c-1)<<"\n";
        }
        /*for(auto& x:seg.tree())cout<<x<<" ";
        cout<<"\n";*/
    }
}

