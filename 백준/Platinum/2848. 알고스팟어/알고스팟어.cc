#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
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
constexpr ll mod=1e9+7;
constexpr ll sz=201;
ll d[9]= {1,-1,-1,0,1,1,0,-1,1};
int mp[26][26]={0,};
bool flag=false;
string f(int st,int en,int dig,vector<vector<char>>& s){
    if(dig>10)return "";
    int i,fr=st,re=st;
    string ret="";
    ret+=s[st][dig];
    for(i=st+1;i<en;i++){
        re++;
        if(s[i][dig]!=s[i-1][dig]){
            ret+=s[i][dig];
            string rule=f(fr,re,dig+1,s);
            //cout<<fr<<" "<<re<<" "<<dig<<" "<<rule<<"\n";
            for(int j=1;j<rule.size();j++){
                if(rule[j]=='?'&&rule[j-1]!='?')flag=true;
                if(rule[j]=='?'||rule[j-1]=='?')continue;
                mp[rule[j-1]-'a'][rule[j]-'a']=1;
            }
            fr=re;
        }
    }
    if(fr!=re){
        re++;
        string rule=f(fr,re,dig+1,s);
        //cout<<fr<<" "<<re<<" "<<dig<<" "<<rule<<"\n";
        for(int j=1;j<rule.size();j++){
            if(rule[j]=='?'&&rule[j-1]!='?')flag=true;
            if(rule[j]=='?'||rule[j-1]=='?')continue;
            mp[rule[j-1]-'a'][rule[j]-'a']=1;
        }
        fr=re;
    }
    //cout<<fr<<" "<<re<<"x\n";
    return ret;
}
void solve(){

    int n,i,j;
    cin>>n;
    vector<int> enter(26,-1);
    vector<vector<char>> a(n+1,vector<char>(12,'?'));
    for(i=0;i<n;i++){
        string x;
        cin>>x;
        for(j=0;j<x.size();j++){a[i][j]=x[j];enter[x[j]-'a']=0;}
    }
    string rule=f(0,n,0,a);
    //cout<<rule<<"\n";
    for(j=1;j<rule.size();j++){
        if(rule[j]=='?'&&rule[j-1]!='?')flag=true;
        if(rule[j]=='?'||rule[j-1]=='?')continue;
        mp[rule[j-1]-'a'][rule[j]-'a']=1;
    }
    /*for(i='a'-1;i<'z'+1;i++)cout<<(char)i<<" ";
    cout<<"\n";
    for(i=0;i<26;i++){
        cout<<(char)(i+'a')<<" ";
        for(j=0;j<26;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<"\n";
    }*/


    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            enter[i]+=mp[j][i];
        }
    }
    //print(enter);
    bool only=true;
    string ans="";
    queue<int> q;
    for(i=0;i<26;i++){
        if(enter[i]==0)q.push(i);
    }
    while(!q.empty()){
        if(q.size()>1)only=false;
        int now=q.front();
        q.pop();
        ans+=(char)(now+'a');
        //cout<<(char)(now+'a')<<" ";
        for(i=0;i<26;i++){
            if(mp[now][i]==1){
                enter[i]--;
                mp[now][i]=0;
                if(enter[i]==0)q.push(i);
            }
        }
    }

    for(i=0;i<26;i++){
        if(enter[i]>0){
            cout<<"!";
            return;
        }
    }
    if(flag){
        cout<<"!";
        return;
    }
    if(only)cout<<ans;
    else cout<<"?";
    return;

}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
