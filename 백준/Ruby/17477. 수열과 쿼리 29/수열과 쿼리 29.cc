#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#define DEBUGu ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
#ifdef DEBUG
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG

#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
#define arrin(x,n) for(ll qwer=0;qwer<n;qwer++)cin>>x[qwer];
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF=1e18;
struct val{
    ll mx=-INF;
    ll mn=INF;
    ll smx=-INF;
    ll smn=INF;
    ll mxcnt=0;
    ll mncnt=0;
    ll b=0;
};
struct lazy{
    ll add=0;
    ll b=0;
    ll mx=0;
    ll mn=0;
    ll mxadd=0;
    ll mnadd=0;
};
class Segtree{
private:
    vector<val> _tree;
    vector<lazy> _lazy;
    ll _sz;

    val init(ll st,ll en,ll node,vector<ll>& a){
        _lazy[node]={0,0,0,0,0,0};
        if(st==en){
            //cout<<st<<" "<<a[st]<<"zz\n";
            return _tree[node]={a[st],a[st],-INF,INF,1,1,0};
        }
        ll mid=(st+en)/2;
        return _tree[node]=mer(init(st,mid,node*2,a),init(mid+1,en,node*2+1,a));
    }
    val mer(val a,val b){
        val imsi={0,0,0,0,0,0,a.b+b.b};
        if(a.mx==b.mx){
            imsi.mx=a.mx;
            imsi.mxcnt=a.mxcnt+b.mxcnt;
            imsi.smx=max(a.smx,b.smx);
        }
        else if(a.mx<b.mx){
            imsi.mx=b.mx;
            imsi.mxcnt=b.mxcnt;
            imsi.smx=max(a.mx,b.smx);
        }
        else{
            imsi.mx=a.mx;
            imsi.mxcnt=a.mxcnt;
            imsi.smx=max(a.smx,b.mx);
        }
        if(a.mn==b.mn){
            imsi.mn=a.mn;
            imsi.mncnt=a.mncnt+b.mncnt;
            imsi.smn=min(a.smn,b.smn);
        }
        else if(a.mn>b.mn){
            imsi.mn=b.mn;
            imsi.mncnt=b.mncnt;
            imsi.smn=min(a.mn,b.smn);
        }
        else{
            imsi.mn=a.mn;
            imsi.mncnt=a.mncnt;
            imsi.smn=min(a.smn,b.mn);
        }
        return imsi;
    }

    void update_lazy(ll st,ll en,ll node){
        if(_tree[node].mx==_tree[node].mn){
            _lazy[node].add+=_lazy[node].mxadd+_lazy[node].mnadd;
            _lazy[node].b+=_lazy[node].mx+_lazy[node].mn;
            _lazy[node].mxadd=_lazy[node].mnadd=_lazy[node].mx=_lazy[node].mn=0;
        }
        if(_tree[node].smx==_tree[node].mn){
            _tree[node].smx+=_lazy[node].mnadd;
        }
        if(_tree[node].smn==_tree[node].mx){
            _tree[node].smn+=_lazy[node].mxadd;
        }
        _tree[node].mx+=_lazy[node].add+_lazy[node].mxadd;
        _tree[node].mn+=_lazy[node].add+_lazy[node].mnadd;
        _tree[node].smx+=_lazy[node].add;
        _tree[node].smn+=_lazy[node].add;
        _tree[node].b+=_lazy[node].b*(en-st+1)+_lazy[node].mx*_tree[node].mxcnt+_lazy[node].mn*_tree[node].mncnt;
        if(st!=en){
            for(ll i=node*2;i<node*2+2;i++){
                if(_tree[i].mx==_tree[i].mn){
                    _lazy[i].add+=_lazy[i].mxadd+_lazy[i].mnadd;
                    _lazy[i].b+=_lazy[i].mx+_lazy[i].mn;
                    _lazy[i].mx=_lazy[i].mn=_lazy[i].mxadd=_lazy[i].mnadd=0;
                }
                if(_tree[i].mx+_lazy[i].mxadd+_lazy[i].add+_lazy[node].mxadd+_lazy[node].add==_tree[node].mx){
                    _lazy[i].mxadd+=_lazy[node].mxadd;
                    _lazy[i].mx+=_lazy[node].mx;
                }
                if(_tree[i].mn+_lazy[i].mnadd+_lazy[i].add+_lazy[node].mnadd+_lazy[node].add==_tree[node].mn){
                    _lazy[i].mnadd+=_lazy[node].mnadd;
                    _lazy[i].mn+=_lazy[node].mn;
                }
                _lazy[i].add+=_lazy[node].add;
                _lazy[i].b+=_lazy[node].b;
            }
        }
        _lazy[node]={0,0,0,0,0,0};
        return;
    }
public:
    Segtree(vector<ll>& other){
        _sz=other.size();
        _tree.resize(_sz*4);
        _lazy.resize(_sz*4);
        init(0,_sz-1,1,other);
    }

    ll query(ll st,ll en,ll node,ll l,ll r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node].b;
        ll mid=(st+en)/2;
        return (query(st,mid,node*2,l,r)+query(mid+1,en,node*2+1,l,r));
    }

    void update_min(ll st,ll en,ll node,ll l,ll r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st||_tree[node].mx<=val)return;
        if(l<=st&&en<=r&&_tree[node].smx<val){
            _lazy[node].mxadd+=val-_tree[node].mx;
            _lazy[node].mx++;
            update_lazy(st,en,node);
            return;
        }
        ll mid=(st+en)/2;
        update_min(st,mid,node*2,l,r,val);
        update_min(mid+1,en,node*2+1,l,r,val);
        _tree[node]=mer(_tree[node*2],_tree[node*2+1]);
        return;
    }

    void update_max(ll st,ll en,ll node,ll l,ll r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st||_tree[node].mn>=val)return;
        if(l<=st&&en<=r&&_tree[node].smn>val){
            _lazy[node].mnadd=val-_tree[node].mn;
            _lazy[node].mn++;
            update_lazy(st,en,node);
            return;
        }
        ll mid=(st+en)/2;
        update_max(st,mid,node*2,l,r,val);
        update_max(mid+1,en,node*2+1,l,r,val);
        _tree[node]=mer(_tree[node*2],_tree[node*2+1]);
        return;
    }

    void update_sum(ll st,ll en,ll node,ll l,ll r,ll val){
        update_lazy(st,en,node);
        if(l>en||r<st)return;
        if(l<=st&&en<=r){
            _lazy[node].add+=val;
            _lazy[node].b++;
            update_lazy(st,en,node);
            return;
        }
        ll mid=(st+en)/2;
        update_sum(st,mid,node*2,l,r,val);
        update_sum(mid+1,en,node*2+1,l,r,val);
        _tree[node]=mer(_tree[node*2],_tree[node*2+1]);
        return;
    }

    vector<val>& tree(){
        return _tree;
    }
    void pr(val a){
        cout<<a.b<<" "<<a.mx<<" "<<a.mn<<" "<<a.smx<<" "<<a.smn<<" "<<a.mxcnt<<" "<<a.mncnt<<"\n";
    }
    void prl(lazy a){
        cout<<a.add<<" "<<a.b<<" "<<a.mx<<" "<<a.mxadd<<" "<<a.mn<<" "<<a.mnadd<<"\n";
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    in>>n;
    ll i;
    vector<ll> a(n,0);
    for(i=0;i<n;i++)in>>a[i];
    Segtree seg(a);
    ll m;
    in>>m;
    while(m--){
        ll inst;
        ll l,r,x;
        in>>inst;
        if(inst==1){
            in>>l>>r>>x;
            if(x==0)continue;
            seg.update_sum(0,n-1,1,l-1,r-1,x);
        }
        if(inst==2){
            in>>l>>r>>x;
            seg.update_max(0,n-1,1,l-1,r-1,x);
        }
        if(inst==3){
            in>>l>>r>>x;
            seg.update_min(0,n-1,1,l-1,r-1,x);
        }
        if(inst==4){
            in>>l>>r;
            out<<seg.query(0,n-1,1,l-1,r-1)<<"\n";
        }
        /*for(auto& x:seg.tree()){
            seg.pr(x);
        }*/
    }
}
