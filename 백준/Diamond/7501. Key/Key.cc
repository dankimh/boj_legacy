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
    vector<ll> primes{2,3,5,7,11,13,17,19,23,29,31,37};
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
ll divcount(ll x,ll p){
    ll cnt=0;
    while(x%p==0){
        cnt++;
        x/=p;
    }
    return cnt;
}
int main(){
    ll a,b;
    cin>>a>>b;
    for(ll i=a;i<=b;i++){
        if(i%2==0)continue;
        if(miller_rabin(i)||i==9)cout<<i<<" ";
        else{
            continue;
            /*vector<ll> factor;
            factorize(i,factor);
            sort(factor.begin(),factor.end());
            factor.push_back(-1);
            ll chk=0,cnt=0;
            for(ll j=0;j<factor.size()-1;j++){
                cnt++;
                if(factor[j]!=factor[j+1]){
                    int ch=1;
                    for(ll k=factor[j];k<i;k+=factor[j]){
                        cnt-=divcount(k,factor[j]);
                        if(cnt<=0){
                            ch=0;
                            cnt=0;
                            break;
                        }
                    }
                    if(!ch){
                        chk=1;
                        cnt=0;
                        break;
                    }
                }
            }
            if(chk)cout<<i<<" ";*/
        }
    }
}