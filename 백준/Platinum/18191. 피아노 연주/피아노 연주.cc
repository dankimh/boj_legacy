#include<bits/stdc++.h>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("input.txt");ofs.open("output.txt");
#ifdef DEBUGs
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG
#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
using namespace std;
typedef long long ll;
typedef long double ld;
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll i;
    vector<ll> p(m);
    for(i=0;i<m;i++)cin>>p[i];

    ll st=0,en=*max_element(p.begin(),p.end())-*min_element(p.begin(),p.end())+1;

    while(st<en){
        ll mid=(st+en)/2;
        ll s=1,e=n;
        bool flag=true;
        //cout<<mid<<"x\n";
        for(i=1;i<m;i++){
            ll a=p[i]-p[i-1];
            ll lo=(ll)ceil((ld)(a-mid)/(ld)k+s),hi=(ll)floor((ld)(a+mid)/(ld)k+s);
            if(lo>hi){
                flag=false;
                break;
            }
            s=lo;
            e=(ll)floor((ld)(a+mid)/(ld)k+e);
            if(s<1&&e<1){
                flag=false;
                break;
            }
            if(s>n&&e>n){
                flag=false;
                break;
            }
            s=max(1ll,s);
            e=min(n,e);
            //cout<<s<<" "<<e<<"b\n";
        }
        if(flag){
            en=mid;
        }
        else{
            st=mid+1;
        }
    }
    cout<<st;
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
