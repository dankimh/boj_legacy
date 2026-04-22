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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve(){

    int N;
    cin>>N;
    ordered_multiset os;
    cout<<(N+1)/2<<endl;
    for(int i=0; i<N;i++){
        int x;
        cin>>x;
        os.insert(x);
        if(i%2==0)cout<<*os.find_by_order(i/2)<<" ";
    }
    cout<<endl;



}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--)solve();
}
