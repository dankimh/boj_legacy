#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
vector<vector<int>> mp;
class euler_segtree{
private:
    ll _sz;
    vector<ll> _tree;
    vector<ll> _lazy;
    vector<ll> _st;
    vector<ll> _en;
    vector<ll> _conv;
    vector<ll> _a;
    void dfs(int now){

        _conv[now]=cnt;//cout<<now<<" "<<cnt<<"d\n";
        _st[now]=++cnt;
        for(auto& i:mp[now])dfs(i);
        _en[now]=cnt;
    }
    ll init(int st,int en,int node){
        if(st==en)return _tree[node]=_a[st];
        int mid=(st+en)/2;
        return _tree[node]=init(st,mid,node*2)+init(mid+1,en,node*2+1);
    }
    void update_lazy(int st,int en,int node){
        if(!_lazy[node])return;
        _tree[node]+=(en-st+1)*_lazy[node];
        if(st!=en){
            _lazy[node*2]+=_lazy[node];
            _lazy[node*2+1]+=_lazy[node];
        }
        _lazy[node]=0;
        return;
    }
    void update(int st,int en,int node,int l,int r,ll val){
        update_lazy(st,en,node);
        if(st>r||en<l)return;
        if(l<=st&&en<=r){
            _lazy[node]+=val;
            update_lazy(st,en,node);
            return;
        }
        int mid=(st+en)/2;
        update(st,mid,node*2,l,r,val);
        update(mid+1,en,node*2+1,l,r,val);
        _tree[node]=_tree[node*2]+_tree[node*2+1];
    }
    ll sum(int st,int en,int node,int l,int r){
        update_lazy(st,en,node);
        if(st>r||en<l)return 0;
        if(l<=st&&en<=r){
            return _tree[node];
        }
        int mid=(st+en)/2;
        return sum(st,mid,node*2,l,r)+sum(mid+1,en,node*2+1,l,r);
    }
public:
    static ll cnt;
    euler_segtree(ll n,vector<ll>& other):_tree(n*4),_lazy(n*4),_st(n),_en(n),_a(n),_conv(n){
        this->_sz=n;
        dfs(0);
        for(int i=0;i<n;i++){
            _a[_st[i]]=other[i];
        }
        init(0,_sz-1,1);
    }
    void update_query(int node,ll val){
        update(0,_sz-1,1,_st[node]+1,_en[node],val);
    }
    ll sum_query(int node){
        return sum(0,_sz-1,1,_st[node],_st[node]);
    }
    vector<ll> conv(){return _conv;}
    vector<ll> st(){return _st;}
    vector<ll> en(){return _en;}

};
ll euler_segtree::cnt=-1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    mp.resize(n);
    vector<ll> money(n);
    int i;
    for(i=0;i<n;i++){
        int x;
        if(i==0){
            cin>>money[i];
        }
        else{
            cin>>money[i]>>x;
            mp[x-1].push_back(i);
        }
    }
    /*for(auto& x:mp){
        for(auto& y:x)cout<<y<<" ";
        cout<<"\n";
    }*/
    euler_segtree seg(n,money);
    /*for(auto& x:seg.st()){
        cout<<x<<" ";

    }cout<<"\n";
    for(auto& x:seg.en()){
        cout<<x<<" ";

    }cout<<"\n";*/
    for(i=0;i<m;i++){
        char p;
        cin>>p;
        if(p=='p'){
            ll a,b;
            cin>>a>>b;
            seg.update_query(a-1,b);
        }
        if(p=='u'){
            ll a;
            cin>>a;
            cout<<seg.sum_query(a-1)<<"\n";
        }
    }
}
