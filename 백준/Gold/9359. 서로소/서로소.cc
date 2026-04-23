#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> gcd(ll n){
    vector<ll> ret;
     for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            while(n%i==0)n/=i;
        }
     }
     if(n>1)ret.push_back(n);
     return ret;
}
ll f(ll siz,vector<ll> pfac,vector<ll> ch,ll cnt){
    if(cnt==pfac.size()){
        ll num=0,mul=1,i;
        for(i=0;i<ch.size();i++){
            if(ch[i]==1){
                mul*=pfac[i];
                num++;
            }
        }
        if(num%2){
            return -siz/mul;
        }
        else return siz/mul;
    }
    else{
        ch.push_back(0);
        ll a1=f(siz,pfac,ch,cnt+1);
        ch[cnt]=1;
        ll a2=f(siz,pfac,ch,cnt+1);
        return a1+a2;
    }
}
void solve(int cs){
    ll a,b,n;
    cin>>a>>b>>n;
    auto pfac=gcd(n);
    vector<ll> ch;
    ll ans1=f(b,pfac,ch,0);
    ll ans2=f(a-1,pfac,ch,0);
    printf("Case #%d: %lld\n",cs,ans1-ans2);
}
int main(){
    int tt;
    cin>>tt;
    for(int i=1;i<=tt;i++)solve(i);
}