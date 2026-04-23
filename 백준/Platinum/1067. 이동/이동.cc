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
    int n;
    cin>>n;
    int i,j;
    vector<ll> x(2*n),y(n);
    for(i=0;i<n;i++){
        cin>>x[i];
        x[i+n]=x[i];
    }
    for(i=0;i<n;i++)cin>>y[n-i-1];
    vector<ll> ans=mul(x,y);
    ll r=-1;
    for(auto& z:ans)r=max(r,z);
    cout<<r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
