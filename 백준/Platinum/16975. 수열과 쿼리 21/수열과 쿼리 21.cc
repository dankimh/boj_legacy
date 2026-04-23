#include<bits/stdc++.h>
using namespace std;
template <typename T>
class lazySegtree{
private:
    vector<T> _tree;
    vector<T> _a;
    vector<T> _lazy;
    int _sz;
    void update_lazy(int st,int en, int node){
        if(_lazy[node]!=0){
            this->_tree[node]+=(en-st+1)*_lazy[node];
            if(st!=en){
                this->_lazy[node*2]+=_lazy[node];
                this->_lazy[node*2+1]+=_lazy[node];
            }
            else{
                this->_a[st]+=_lazy[node];
            }
            this->_lazy[node]=0;
        }
    }
public:
    lazySegtree(int n,vector<T>& other){
        this->_sz=n;
        this->_tree.resize(n*4);
        this->_lazy.resize(n*4,0);
        this->_a.resize(n+1,0);
        copy(other.begin(),other.end(),this->_a.begin());
    }
    T init(int st, int en, int node){
        if(st==en)return this->_tree[node]=_a[st];
        int mid=(st+en)/2;
        return this->_tree[node]=init(st,mid,node*2)+init(mid+1,en,node*2+1);
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
            this->_a[st]+=diff;
            return;
        }
        int mid=(st+en)/2;
        if(idx<=mid)update_tree(st,mid,node*2,idx,diff);
        else update_tree(mid+1,en,node*2+1,idx,diff);
    }
    T update_range(int st,int en,int node,int l,int r,int diff){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r){
            this->_tree[node]+=(en-st+1)*diff;
            if(st!=en){
                this->_lazy[node*2]+=diff;
                this->_lazy[node*2+1]+=diff;
            }
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=update_range(st,mid,node*2,l,r,diff)+update_range(mid+1,en,node*2+1,l,r,diff);
    }
    vector<T>& tree(){
        return _tree;
    }
};
int main(){
    int n;
    scanf("%d",&n);
    vector<long long> a(n);
    int i;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    lazySegtree<long long> seg(n,a);
    seg.init(0,n-1,1);
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int inst;
        scanf("%d",&inst);
        if(inst==1){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            seg.update_range(0,n-1,1,x-1,y-1,z);
        }
        if(inst==2){
            int x;
            scanf("%d",&x);
            printf("%lld\n",seg.sum(0,n-1,1,x-1,x-1));
        }
    }
}
