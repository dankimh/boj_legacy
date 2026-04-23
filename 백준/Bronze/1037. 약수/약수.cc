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
    int n,i;
    cin>>n;
    int mx=-1,mn=1010101;
    for(i=0;i<n;i++){
        int a;
        cin>>a;
        if(mx<a)mx=a;
        if(mn>a)mn=a;
    }
    cout<<mx*mn;
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


