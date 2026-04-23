#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(),a.end()
class Segtree{
private:
    vector<vector<ll>> _tree;
    ll _sz;
    void init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            _tree[node]={a[st]};
            return;
        }
        int mid=(st+en)/2;
        init(st,mid,node*2,a);
        init(mid+1,en,node*2+1,a);
        _tree[node].resize(en-st+1);
        merge(all(_tree[node*2]),all(_tree[node*2+1]),_tree[node].begin());
        return;
    }
public:
    Segtree(vector<ll>& other){
        this->_sz=other.size();
        this->_tree.resize(_sz*4);
        init(0,_sz-1,1,other);
    }
    ll find_swap(int st,int en,int node){
        if(st==en){
            return 0;
        }
        int mid=(st+en)/2;
        ll ret=find_swap(st,mid,node*2)+find_swap(mid+1,en,node*2+1);
        for(int i=0;i<mid-st+1;i++){
            ret+=lower_bound(all(_tree[node*2+1]),_tree[node*2][i])-_tree[node*2+1].begin();
        }
        return ret;
    }
    void tree(){
        for(auto &u:_tree){
            for(auto &po:u){
                cout<<po<<" ";
            }
            cout<<"\n";
        }
        cout<<"tr\n";
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int i;
    vector<ll> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    Segtree seg(a);
    //seg.tree();
    cout<<seg.find_swap(0,n-1,1);
}