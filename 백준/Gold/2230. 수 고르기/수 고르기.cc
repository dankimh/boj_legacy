#include<bits/stdc++.h>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("input.txt");ofs.open("output.txt");
#ifdef DEBUG
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    ll i;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll st=0,en=0,ans=LLONG_MAX;
    while(st<=en){
        //cout<<st<<" "<<en<<"x\n";
        if(a[en]-a[st]<m){
            if(en==n-1)break;
            en++;
        }
        else if(a[en]-a[st]==m){
            ans=m;
            break;
        }
        else{
            if(ans>a[en]-a[st])ans=a[en]-a[st];
            st++;
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
}
