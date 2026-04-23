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
void solve(){
    ll n,c;
    cin>>n>>c;
    ll i;
    vector<ll> a(n);
    vector<vector<ll>> cnt(c);
    for(i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]-1].push_back(i);
    }
    ll q;
    cin>>q;
    //unsigned seed=chrono::system_clock::now().time_since_epoch().count();
    random_device rd;
    mt19937_64 rng(rd());
    while(q--){
        ll l,r,z=-1;
        cin>>l>>r;
        uniform_int_distribution<mt19937_64::result_type> dist(l-1,r-1);
        ll k=100;
        dist(rng);
        while(k--){
            ll next=a[dist(rng)];
            ll x=upper_bound(cnt[next-1].begin(),cnt[next-1].end(),r-1)-lower_bound(cnt[next-1].begin(),cnt[next-1].end(),l-1);
            if(x>(r-l+1)/2){
                z=next;
                break;
            }
        }
        if(z>0){
            cout<<"yes "<<z<<"\n";
        }
        else cout<<"no\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
