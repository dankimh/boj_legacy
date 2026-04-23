#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2e60;
int main(){
    int n;
    cin>>n;
    ll ans=1;
    for(ll i=2;i<=n;i++){
        ans*=i;
        while(ans%10==0)ans/=10;
        ans%=(ll)(1e12);
    }
    string a=to_string(ans);
    int x=a.size()-5;
    if(x<0)x=0;
    for(ll i=x;i<a.size();i++){
        if(i<0)continue;
        cout<<a[i];
    }

}