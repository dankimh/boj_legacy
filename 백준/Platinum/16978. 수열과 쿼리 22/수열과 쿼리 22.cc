#include<bits/stdc++.h>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("input.txt");ofs.open("output.txt");
#ifdef DEBUG
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG
#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
using namespace std;
typedef long long ll;
/*vector<bool> f(ll val){
    vector<bool> ret(30);
    for(int i=29;i>=0;i--){
        ret[i]=val%2;
        val/=2;
    }
    return ret;
}
class Trie{
private:
    ll finish;
    Trie* child[2];

    void add(vector<bool>& key,ll it){
        if(it==key.size()){
            finish++;
        }
        else{
            if(child[key[it]]==nullptr){
                child[key[it]]=new Trie();
            }
            child[key[it]]->add(key,it+1);
        }
    }
    Trie* fin(vector<bool>& key,ll it){
        if(it==key.size()){
            if(finish)return this;
            else return nullptr;
        }
        if(child[key[it]]==nullptr)return nullptr;
        return child[key[it]]->fin(key,it+1);
    }
    bool del(vector<bool>& key,ll it){
        if(it==key.size()){
            finish--;
            if(!finish){
                if(child[0]==nullptr&&child[1]==nullptr)return true;
                else return false;
            }
            else return false;
        }
        if(child[key[it]]==nullptr)return false;
        bool a=child[key[it]]->del(key,it+1);
        if(a){
            delete child[key[it]];
            child[key[it]]=nullptr;
            if(child[!key[it]]==nullptr)return true;
            else return false;
        }
        else return false;
    }

    ll mx_xor(vector<bool>& key,ll it){
        if(it==key.size()){
            return 0;
        }
        int want=!key[it];
        //cout<<it<<" "<<want<<"it\n";
        if(child[want]!=nullptr){
            return child[want]->mx_xor(key,it+1)+(1<<(29-it));
        }
        else{
            return child[!want]->mx_xor(key,it+1);
        }
    }

public:

    Trie():finish(0){
        this->child[0]=this->child[1]=nullptr;
    }
    ~Trie(){
        for(int i=0;i<2;i++){
            if(child[i])delete child[i];
        }
    }

    void insert(ll val){
        vector<bool> a=f(val);
        add(a,0);
        return;
    }

    bool erase(ll val){
        vector<bool> a=f(val);
        return del(a,0);
    }

    ll max_xor(ll val){
        vector<bool> a=f(val);
        return mx_xor(a,0);
    }

    bool find(ll val){
        vector<bool> a=f(val);
        if(fin(a,0)!=nullptr)return true;
        else return false;
    }
};
void solve(){
    ll n;
    cin>>n;
    Trie t;
    t.insert(0);
    while(n--){
        ll inst,x;
        cin>>inst>>x;
        if(inst==1){
            t.insert(x);
        }
        if(inst==2){
            t.erase(x);
            //cout<<t.find(8)<<" "<<8<<"f\n";
        }
        if(inst==3){
            cout<<t.max_xor(x)<<"\n";
        }

    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}*/

template <typename T>
class Segtree{
private:
    vector<T> _tree;
    vector<T> _a;
    int sz;
public:
    Segtree(int n,vector<T>& other){
        this->sz=n;
        this->_tree.resize(n*4);
        this->_a.resize(n+1,0);
        copy(other.begin(),other.end(),this->_a.begin());
    }
    T init(int st, int en, int node){
        if(st==en)return this->_tree[node]=_a[st];
        int mid=(st+en)/2;
        return this->_tree[node]=init(st,mid,node*2)+init(mid+1,en,node*2+1);
    }
    T sum(int st,int en, int node, int l,int r){
        if(l>en||r<st)return 0;
        if(l<=st&&en<=r)return _tree[node];
        int mid=(st+en)/2;
        return sum(st,mid,node*2,l,r)+sum(mid+1,en,node*2+1,l,r);
    }

    void update_tree(int st,int en,int node,int idx,T diff){
        this->_tree[node]+=diff;
        if(st==en)return;
        int mid=(st+en)/2;
        if(idx<=mid)update_tree(st,mid,node*2,idx,diff);
        else update_tree(mid+1,en,node*2+1,idx,diff);
    }
    void update_a(int idx,T val){
        this->_a[idx]=val;
    }
    void update(int idx,T val){
        update_tree(0,sz-1,1,idx,val-_a[idx]);
        update_a(idx,val);
    }
    vector<T>& tree(){
        return _tree;
    }
};
bool cmp(vector<ll> &a,vector<ll>& b){
    return a[1]<b[1];
}
int main(){
    ll n,m,i;
    cin>>n;
    vector<ll> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    Segtree<ll> s(n,a);
    s.init(0,n-1,1);
    cin>>m;
    vector<vector<ll>> query,q;
    ll z=0;
    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        if(a==1){
            vector<ll> x;
            x.push_back(b);
            x.push_back(c);
            query.push_back(x);
        }
        if(a==2){
            int d;
            cin>>d;
            vector<ll> x;
            x.push_back(z);
            x.push_back(b);
            x.push_back(c);
            x.push_back(d);
            q.push_back(x);
            z++;
        }
    }

    sort(q.begin(),q.end(),cmp);
    /*for(auto &x:q){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<"x\n";
    }*/
    ll one=0,two=0;
    vector<ll> ans(z);

    while(two<z&&q[two][1]==0){
        ans[q[two][0]]=s.sum(0,n-1,1,q[two][2]-1,q[two][3]-1);
        //cout<<ans[q[two][0]]<<"z\n";
        two++;
    }
    for(i=0;i<query.size();i++){
        s.update(query[i][0]-1,query[i][1]);
        while(two<z&&q[two][1]==i+1){
            //cout<<q[two][2]<<" "<<q[two][3]<<" ";
            ans[q[two][0]]=s.sum(0,n-1,1,q[two][2]-1,q[two][3]-1);
            //cout<<ans[q[two][0]]<<"z\n";
            two++;
        }
    }//cout<<"x";
    for(auto& x:ans){
        cout<<x<<"\n";
    }
}
