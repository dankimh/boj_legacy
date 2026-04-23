#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll i;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll m;
    cin>>m;
    while(m--){
        ll x;
        cin>>x;
        ll now=*lower_bound(a.begin(),a.end(),x);
        if(now==x)cout<<"1 ";
        else cout<<"0 ";
    }
}