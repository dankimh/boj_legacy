#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
class lazySegtree{
private:
    vector<T> _tree;
    vector<T> _a;
    vector<T> _lazy;
    int _sz;
    void update_lazy(int st,int en, int node){
        if(_lazy[node]!=0){
            this->_tree[node]+=((en-st+1)*_lazy[node]);
            if(st!=en){
                this->_lazy[node*2]+=_lazy[node];
                this->_lazy[node*2+1]+=_lazy[node];
            }
            this->_lazy[node]=0;
        }
    }
    T i(int st, int en, int node){
        if(st==en)return this->_tree[node]=_a[st];
        int mid=(st+en)/2;
        return this->_tree[node]=i(st,mid,node*2)+i(mid+1,en,node*2+1);
    }
public:
    lazySegtree(int n,vector<T>& other){
        this->_sz=n;
        this->_tree.resize(n*4);
        this->_lazy.resize(n*4,0);
        this->_a.resize(n+1,0);
        copy(other.begin(),other.end(),this->_a.begin());
    }
    void init(){
        i(0,_sz-1,1);
    }
    T sum(int st,int en, int node, int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node];
        int mid=(st+en)/2;
        return sum(st,mid,node*2,l,r)+sum(mid+1,en,node*2+1,l,r);
    }
    void update_tree(int st,int en,int node,int idx,T diff){
        update_lazy(st,en,node);
        this->_tree[node]+=diff;
        if(st==en){
            return;
        }
        int mid=(st+en)/2;
        if(idx<=mid)update_tree(st,mid,node*2,idx,diff);
        else update_tree(mid+1,en,node*2+1,idx,diff);
    }
    T update_range(int st,int en,int node,int l,int r,T diff){
        //cout<<st<<" "<<en<<" "<<diff;
        update_lazy(st,en,node);
        if(l>en||r<st){
            //cout<<"1\n";
            return _tree[node];
        }
        if(l<=st&&en<=r){
            this->_tree[node]+=((en-st+1)*diff);
            if(st!=en){
                this->_lazy[node*2]+=diff;
                this->_lazy[node*2+1]+=diff;
            }
            //cout<<"2\n";
            return this->_tree[node];
        }
        int mid=(st+en)/2;
        //cout<<"3\n";
        T a1=update_range(st,mid,node*2,l,r,diff);
        T a2=update_range(mid+1,en,node*2+1,l,r,diff);
        //cout<<a1<<" "<<a2<<"xx\n";
        return this->_tree[node]=a1+a2;//update_range(st,mid,node*2,l,r,diff)+update_range(mid+1,en,node*2+1,l,r,diff);
    }
    vector<T>& tree(){
        return _tree;
    }
    vector<T>& lazy(){
        return _lazy;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    vector<ll> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    lazySegtree<ll> seg(n,a);
    seg.init();
    for(i=0;i<m+k;i++){
        ll inst;
        cin>>inst;
        if(inst==1){
            ll b,c,d;
            cin>>b>>c>>d;
            seg.update_range(0,n-1,1,b-1,c-1,d);
        }
        else if(inst==2){
            ll b,c;
            cin>>b>>c;
            cout<<seg.sum(0,n-1,1,b-1,c-1)<<"\n";
        }
        /*for(auto &x:seg.tree()){
            cout<<x<<" ";
        }
        cout<<"\n";
        for(auto &x:seg.lazy()){
            cout<<x<<" ";
        }
        cout<<"\n";*/
    }
}
int maxin(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n);
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    lazySegtree<ll> seg(n,a);
    seg.init();
    int m;
    cin>>m;
    for(i=0;i<m;i++){

    }
}
