#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll mul(ll a,ll b,ll mod){
    return (__int128)a*b%mod;
}
ll power(ll a,ll b,ll mod){
    ll ret=1;
    while(b>0){
        if(b%2)ret=mul(a,ret,mod);
        b/=2;
        a=mul(a,a,mod);
    }
    return ret%mod;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
bool cond(ll n,ll p){
    if(p%n==0)return false;
    ll d=n-1;
    while(1){
        ll z=power(p,d,n);
        if(z==n-1)return false;
        if(d%2)return (z!=1);
        d/=2;
    }
}

bool miller_rabin(ll n){
    vector<ll> primes{2,7,61};
    for(auto& p:primes){
        if(p==n)return true;
        if(cond(n,p))return false;
    }
    return true;
}
ll abs(ll x){return x>0?x:-x;}
void factorize(ll n,vector<ll>& factor){
    if(n==1)return;
    if(n%2==0){
        factor.push_back(2);
        factorize(n/2,factor);
        return;
    }
    if(miller_rabin(n)){
        factor.push_back(n);
        return;
    }
    ll a,b,c,g = n;
    auto f=[&](ll x){
        return (c+mul(x,x,n))%n;
    };
    do {
        if(g==n){
            a=b=rand()%(n-2)+2;
            c=rand()%20+1;
        }
        a=f(a);
        b=f(f(b));
        g=gcd(abs(a-b),n);
    } while(g==1);
    factorize(n/g,factor);
    factorize(g,factor);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        ll n,ans=2;
        cin>>n;
        if(n==0)break;
        vector<ll> factor;
        if(n%2){
            factorize(n,factor);
        }
        else{
            n/=(n&-n);
            factorize(n,factor);
        }
        sort(factor.begin(),factor.end());
        auto imsi=factor;
        imsi.erase(unique(imsi.begin(),imsi.end()),imsi.end());
        //cout<<n<<"n\n";

        for(auto& x:imsi){
            ans*=(2*(upper_bound(factor.begin(),factor.end(),x)-lower_bound(factor.begin(),factor.end(),x))+1);
        }
        cout<<ans<<"\n";
    }
}