#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> coo;
vector<int> coor;
vector<bool> ch;
class lazySegtree{//oddnum
private:
    vector<int> _tree;
    vector<bool> _lazy;
    int _sz;
    void update_lazy(int st,int en,int node){
        int mn,mx;
        if(!ch[coor[st]])mn=coor[st];
        else mn=coor[st-1]+1;
        if(!ch[coor[en]])mx=coor[en];
        else mx=coor[en+1]-1;
        if(!_lazy[node])return;
        int sz=mx-mn+1;
        //cout<<st<<" "<<en<<" "<<sz<<" "<<_lazy[node]<<" "<<_tree[node].cnt<<"asdf\n";
        _tree[node]=sz-_tree[node];
        if(st!=en){
            _lazy[node*2]=_lazy[node*2]^_lazy[node];
            _lazy[node*2+1]=_lazy[node*2+1]^_lazy[node];
        }
        _lazy[node]=0;
        return;
    }
public:
    lazySegtree(int n){
        this->_sz=n;
        this->_tree.resize(_sz*4,0);
        this->_lazy.resize(_sz*4,false);
    }
    void update(int st,int en, int node, int l,int r,int w){
        update_lazy(st,en,node);
        if(l>en||r<st)return;
        if(l<=st&&en<=r){
            _lazy[node]=_lazy[node]^w;
            update_lazy(st,en,node);
            return;
        }
        int mid=(st+en)/2;
        update(st,mid,node*2,l,r,w);
        update(mid+1,en,node*2+1,l,r,w);
        _tree[node]=_tree[node*2]+_tree[node*2+1];
        return;
    }
    int cnt_odd(int st,int en,int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r){
            return _tree[node];
        }
        int mid=(st+en)/2;
        return cnt_odd(st,mid,node*2,l,r)+cnt_odd(mid+1,en,node*2+1,l,r);
    }
    
};
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
int find_idx(int val){
    return lower_bound(coor.begin(),coor.end(),val)-coor.begin();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int i;
    vector<vector<int>> query(m+1,vector<int>(4,0));
    
    for(i=0;i<m;i++){
        for(int j=0;j<3;j++)cin>>query[i][j];
        if(query[i][0]==1){
            ll x;
            cin>>x;
            query[i][3]=x%2;
        }
        coo.push_back(query[i][1]);
        coo.push_back(query[i][2]);
    }
    sort(coo.begin(),coo.end());
    coo.erase(unique(coo.begin(),coo.end()),coo.end());
    ll nn=coo.size();
    ch.resize(n+2,0);
    coor=coo;
    for(i=1;i<nn;i++){
        if(coo[i]-coo[i-1]>1){
            coor.push_back((coo[i-1]+coo[i])/2);
            ch[(coo[i-1]+coo[i])/2]=true;
        }
    }
    sort(coor.begin(),coor.end());
    nn=coor.size();
    lazySegtree seg(nn);
    /*for(auto& z:seg.tree()){
            cout<<z<<" ";
        }
        cout<<"\n";*/
    for(i=0;i<m;i++){
        int x=query[i][0];
        int l=query[i][1],r=query[i][2];
        //cout<<find_idx(l)<<" "<<find_idx(r)<<"lr\n";
        //cout<<coor[find_idx(l)]<<" "<<coor[find_idx(r)]<<"colr\n";
        if(x==1){
            int w=query[i][3];
            seg.update(0,nn-1,1,find_idx(l),find_idx(r),w);
        }
        else{
            int odd=seg.cnt_odd(0,nn-1,1,find_idx(l),find_idx(r));
            cout<<odd<<" "<<(r-l+1)-odd<<"\n";
        }
        
    }
}