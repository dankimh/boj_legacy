#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x,ll n){
    ll i,ret=0;
    for(i=1;i<=n;i++){
        ret+=(min(n,x/i));
    }
    return ret;
}
int main(){
    ll n,i,j,k;
    cin>>n>>k;
    ll st=1,en=k+1;
    while(st<en){

        ll mid=(st+en)/2;
        //cout<<st<<" "<<en<<" "<<f(mid,n)<<"\n";
        if(f(mid,n)<k)st=mid+1;
        else en=mid;
    }
    cout<<st;
}