#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll fac(ll x){
    if(x==-1)return -1;
    if(x==1)return 1;
    return x*fac(x-1);
}
int main(){
    ll n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x==1){
            cout<<"1\n";
            continue;
        }
        if(x==4){
            cout<<"1\n";
            continue;
        }
        vector<ll> f;
        factorize(x,f);
        sort(f.begin(),f.end());
        int ch=0;
        ll ans=1;
        for(int j=1;j<f.size();j++){
            ans++;
            if(f[j-1]==f[j]){
                ans=-1;
                break;
            }
        }
        cout<<fac(ans)<<"\n";
    }
}