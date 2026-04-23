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
    ll n;
    cin>>n;
    for(ll i=0;i<20000;i++){
        
        cout<<"? 1\n"<<flush;
        char x;
        cin>>x;
        if(x=='Y'){cout<<"! 1\n"<<flush;return;}
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
