#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=(ll)1e18+31,g=42;
ll ppow(ll a,ll b,ll p){
    ll x=b,ret=1;
    while(x>0){
        if(x%2){
            ret=__int128_t(ret)*a%M;
            ret%=p;
        }
        a=__int128_t(a)*a%M;
        x/=2;
    }
    return ret%p;
}
int main(){
    ll n;
    cin>>n;
    ll a=300;
    for(ll i=1000000;i>n;i--){
        ll imsi=ppow(42,a,M);
        a=imsi;
    }
    cout<<a;
}