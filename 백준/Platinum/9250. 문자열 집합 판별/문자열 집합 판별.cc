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
    Trie* child[26];

    Trie* fail;

    void add(string& key,ll it){
        int now=key[it]-'a';
        if(it==key.size()){
            finish++;
        }
        else{
            if(child[now]==nullptr){
                child[now]=new Trie();
            }
            child[now]->add(key,it+1);
        }
    }
    Trie* fin(string& key,ll it){
        if(it==key.size()){
            if(finish)return this;
            else return nullptr;
        }
        int now=key[it]-'a';
        if(child[now]==nullptr)return nullptr;
        return child[now]->fin(key,it+1);
    }

    bool del(string& key,ll it){
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

    ll cnt(string& key,ll it){
        if(it==key.size()){
            if(finish)return 0;
            else return -1;
        }
        int now=key[it]-'a';
        ll down=child[now]->cnt(key,it+1);
        if(down==-1)return -1;
        ll flag=0;
        for(int i=0;i<26;i++){
            if(child[i]!=nullptr)flag++;
        }
        //cout<<key[it]<<flag<<"x ";
        if(flag==1){
            if(finish||it==0)return down+1;
            else return down;
        }
        else return down+1;
    }

    void mk_fail(Trie* root){
        int i;
        queue<Trie*> q;
        q.push(root);
        while(!q.empty()){
            Trie* now=q.front();
            q.pop();

            for(i=0;i<26;i++){
                Trie* next=now->child[i];
                if(!next)continue;

                if(now==root)next->fail=root;
                else{
                    Trie* dest=now->fail;
                    while(dest!=root&&!dest->child[i])dest=dest->fail;
                    if(dest->child[i])dest=dest->child[i];
                    next->fail=dest;
                }
                if(next->fail->finish)next->finish++;
                q.push(next);
            }
        }
    }

public:

    Trie():finish(0){
        for(int i=0;i<26;i++)this->child[i]=nullptr;
        this->fail=nullptr;
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(child[i])delete child[i];
        }
    }

    void insert(string a){
        add(a,0);
        return;
    }

    bool erase(string a){
        return del(a,0);
    }

    bool find(string a){
        if(fin(a,0)!=nullptr)return true;
        else return false;
    }

    ll ans(string a){
        return cnt(a,0);
    }

    void make_fail(){
        mk_fail(this);
    }

    bool substring(string a){
        bool flag=0;
        Trie* now=this;
        for(auto& next:a){
            next-='a';
            while(now!=this&&!now->child[next])now=now->fail;
            if(now->child[next])now=now->child[next];
            if(now->finish){
                flag=true;
                break;
            }
        }
        return flag;
    }

};
void solve(){
    ll n;
    cin>>n;
    Trie* root=new Trie();
    ll i;
    for(i=0;i<n;i++){
        string a;
        cin>>a;
        root->insert(a);
    }
    root->make_fail();
    ll m;
    cin>>m;
    while(m--){
        string a;
        cin>>a;

        cout<<((root->substring(a))?"YES\n":"NO\n");
    }
    delete root;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*cout<<fixed;
    cout.precision(2);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}


