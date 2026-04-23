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
constexpr double pi=acos(-1);
ll d[9]= {1,-1,-1,0,1,1,0,-1,1};

using cd=complex<double>;

void fft(vector<cd>& a,bool inv){
    int s=a.size();
    for(int i=1,j=0;i<s;i++){
        int bit=s>>1;

        while(j>=bit){
            j-=bit;
            bit>>=1;
        }
        j+=bit;
        if(i<j)swap(a[i],a[j]);
    }

    for(int k=1;k<s;k<<=1){
        double ang=(inv?pi/k:-pi/k);
        cd we(cos(ang),sin(ang));
        for(int i=0;i<s;i+=(k<<1)){
            cd w(1,0);
            for(int j=0;j<k;j++,w*=we){
                cd e=a[i+j],o=a[i+j+k];
                a[i+j]=e+w*o;
                a[i+j+k]=e-w*o;
            }
        }
    }
    if(inv){
        for(int i=0;i<s;i++)a[i]/=s;
    }
    return;
}
vector<ll> mul(vector<ll>& a, vector<ll>& b){

    vector<cd> ta(a.begin(),a.end()),tb(b.begin(),b.end());
    int s=2;
    while(s<a.size()+b.size())s<<=1;

    ta.resize(s);fft(ta,false);
    tb.resize(s);fft(tb,false);

    for(int i=0;i<s;i++)ta[i]*=tb[i];
    fft(ta,true);

    vector<ll> w(s);

    for(int i=0;i<s;i++)w[i]=round(ta[i].real());

    return w;
}

void solve(){
    string a,b;
    cin>>a>>b;
    if(a=="0"||b=="0"){
        cout<<"0";
        return;
    }
    int i;
    vector<ll> aa(a.size()),bb(b.size());
    for(i=0;i<a.size();i++){
        aa[i]=(a[i]-'0');
    }
    for(i=0;i<b.size();i++){
        bb[i]=(b[i]-'0');
    }
    vector<ll> ans=mul(aa,bb);
    //print(ans);
    vector<int> s;
    int sz=a.size()+b.size()-2;
    int q=0;
    //cout<<sz<<"x\n";
    for(i=sz;i>=0;i--){
        int ad=ans[i];
        s.push_back((ad+q)%10);
        q=(ad+q)/10;
    }
    while(q>0){
        s.push_back(q%10);
        q/=10;
    }
    for(i=s.size()-1;i>=0;i--)cout<<s[i];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
