#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ppow(ll a,ll b,ll p){
    ll x=b,ret=1;
    while(x>0){
        if(x%2){
            ret*=a;
            ret%=p;
        }
        a*=a;
        a%=p;
        x/=2;
    }
    return ret%p;
}
int main(){
    ll p,b,n;
    while(cin>>p>>b>>n){
    ll i,j;
    
    //b^x=n mod p
    ll m=(ll)sqrt(p)+1;
    map<ll,ll> a;
    ll x=1;
    for(i=0;i<m;i++){
        if(a.find(x)==a.end())a[x]=i;
        x*=b;
        x%=p;
    }
    ll g=n,aa,z=ppow(ppow(b,m,p),p-2,p),t=1;
    for(i=0;i<m;i++){
        ll imsi=n*t;
        imsi%=p;
        if(a.find(imsi)!=a.end()){
            aa=imsi;
            break;
        }
        t*=z;
        t%=p;
    }
    if(i==m)cout<<"no solution\n";
    else cout<<i*m+a[aa]<<"\n";
    }
}