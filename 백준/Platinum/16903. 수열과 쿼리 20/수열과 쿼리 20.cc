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
vector<bool> f(ll val){
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
        //if(child[key[it]]!=nullptr)cout<<key[it]<<" "<<it<<"\n";;
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
            /*auto x=child[want]->mx_xor(key,it+1)+(1<<(29-it));
            cout<<it<<" "<<x<<"x\n";
            return x;*/
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
}


