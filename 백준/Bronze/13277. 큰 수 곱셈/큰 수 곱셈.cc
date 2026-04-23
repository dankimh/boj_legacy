#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#include<numbers>
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

using cd=complex<ld>;
vector<cd> fft(const vector<cd>& a, int pol=1){
    int n=1;
    const int a_sz=static_cast<int>(a.size());
    while(n<a_sz){
        n<<=1;
    }
    ld pi=numbers::pi_v<ld>;
    vector<cd> r(n);
    for(int i=0;i<n;++i){
        int s=0;
        for(int b=1,d=n/2;b<n;b<<=1,d>>=1){
            if(b&i){
                s+=d;
            }
        }
        r[s]=i<a_sz?a[i]:0;
    }
    for(int m=2;m<=n;m<<=1){
        cd we=exp(cd(0,pol*2*pi/m));
        for(int i=0;i<n;i+=m){
            cd w=1;
            for(int j=i;j<i+m/2;++j,w*=we){
                int j2=j+m/2;
                cd temp1=r[j],temp2=r[j2];
                r[j]=temp1+w*temp2;
                r[j2]=temp1-w*temp2;
            }
        }
    }

    if(pol==-1){
        for(auto& c:r){
            c/=n;
        }
    }

    return r;
}
vector<cd> mul(vector<cd> a, vector<cd> b){
    const int target_size=static_cast<int>(a.size()+b.size()-1);
    a.resize(target_size,0);
    b.resize(target_size,0);

    auto ta=fft(a),tb=fft(b);
    vector<cd> ret(ta.size());
    for(int i=0;i<ret.size();i++){
        ret[i]=ta[i]*tb[i];
    }
    return fft(ret,-1);
}

void solve(){
    string a,b;
    cin>>a>>b;
    int i;
    vector<cd> aa,bb;
    for(i=0;i<a.size();i++){
        aa.push_back(a[i]-'0');
    }
    for(i=0;i<b.size();i++){
        bb.push_back(b[i]-'0');
    }
    auto ans=mul(aa,bb);
    //print(ans);
    string s="";
    int sz=a.size()+b.size()-2;
    int q=0;
    //cout<<sz<<"x\n";
    for(i=sz;i>=0;i--){
        int ad=static_cast<int>(round(ans[i].real()));
        //cout<<ad<<"y\n";
        s+=((ad+q)%10+'0');
        q=(ad+q)/10;
    }
    while(q>0){
        s+=(q%10+'0');
        q/=10;
    }
    for(i=s.size()-1;i>=0;i--)cout<<s[i];
}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
