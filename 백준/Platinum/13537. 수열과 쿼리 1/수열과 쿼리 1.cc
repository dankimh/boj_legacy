#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class mergeTree{
private:
    vector<vector<ll>> _tree;
    ll _sz;
    void init(int st,int en,int node,vector<ll> &a){
        if(st==en){
            this->_tree[node]={a[st]};
            return;
        }
        this->_tree[node].resize(en-st+1);
        int mid=(st+en)/2;
        init(st,mid,node*2,a);
        init(mid+1,en,node*2+1,a);
        auto a1=_tree[node*2];
        auto a2=_tree[node*2+1];
        merge(a1.begin(),a1.end(),a2.begin(),a2.end(),_tree[node].begin());
        return;
    }
public:
    mergeTree(vector<ll>& a){
        this->_sz=a.size();
        this->_tree.resize(_sz*4);
        init(0,_sz-1,1,a);
    }
    ll find_k(int st,int en,int node,int l,int r,ll k){
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node].end()-upper_bound(_tree[node].begin(),_tree[node].end(),k);
        int mid=(st+en)/2;
        return find_k(st,mid,node*2,l,r,k)+find_k(mid+1,en,node*2+1,l,r,k);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll i;
    for(i=0;i<n;i++)cin>>a[i];
    mergeTree mer(a);
    ll m;
    cin>>m;
    for(i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        cout<<mer.find_k(0,n-1,1,x-1,y-1,z)<<"\n";
    }
}
