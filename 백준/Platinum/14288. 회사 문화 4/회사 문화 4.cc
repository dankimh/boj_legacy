#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> mp;
vector<ll> _st;
vector<ll> _en;
vector<ll> a;
void dfs(int now,int d){
    static ll cnt=-1;
    //cout<<now<<" "<<d<<"d\n";
    _st[now]=++cnt;
    for(auto& i:mp[now]){
        dfs(i,d+1);
    }
    _en[now]=cnt;
}
class euler_segtree{
private:
    ll _sz;
    vector<ll> _tree;
    vector<ll> _lazy;
    vector<ll> _a;
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
    static ll cntup,cntdown;
    euler_segtree(ll n,vector<ll>& other):_tree(n*4),_lazy(n*4),_a(n){
        this->_sz=n;
        this->_a=other;
        init(0,_sz-1,1);
    }
    void update_query_up(int node,ll val){
        update(0,_sz-1,1,_st[node],_st[node],val);
    }
    ll sum_query_up(int node){
        return sum(0,_sz-1,1,_st[node],_en[node]);
    }
    void update_query_down(int node,ll val){
        update(0,_sz-1,1,_st[node],_en[node],val);
    }
    ll sum_query_down(int node){
        return sum(0,_sz-1,1,_st[node],_st[node]);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    mp.resize(n);
    _st.resize(n);
    _en.resize(n);
    a.resize(n,0);
    vector<ll> money(n,0);
    int i;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0){
            continue;
        }
        else{
            mp[x-1].push_back(i);
        }
    }
    dfs(0,1);
    for(int i=0;i<n;i++){
        a[_st[i]]=money[i];
    }
    /*for(auto& x:mp){
        for(auto& y:x)cout<<y<<" ";
        cout<<"\n";
    }*/
    euler_segtree segup(n,money);
    euler_segtree segdown(n,money);
    /*for(auto& x:seg.st()){
        cout<<x<<" ";

    }cout<<"\n";
    for(auto& x:seg.en()){
        cout<<x<<" ";

    }cout<<"\n";*/
    int sign=1;
    for(i=0;i<m;i++){
        int p;
        cin>>p;
        if(p==1){
            ll a,b;
            cin>>a>>b;
            if(sign>0)segdown.update_query_down(a-1,b);
            else segup.update_query_up(a-1,b);
        }
        if(p==2){
            ll a;
            cin>>a;
            cout<<segdown.sum_query_down(a-1)+segup.sum_query_up(a-1)<<"\n";
        }
        if(p==3){
            sign=-sign;
        }
    }
}
