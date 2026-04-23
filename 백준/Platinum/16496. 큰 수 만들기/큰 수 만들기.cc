#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll f(ll a,ll b){
    ll ans=b,i=1;
    if(b==0)return a*10;
    while(b>0){
        b/=10;
        i*=10;
    }
    ans+=a*i;
    return ans;
}
bool cmp(const ll a,const ll b){
    ll aa=f(a,b);
    ll bb=f(b,a);
    return aa>bb;
}
int main(){
    ll n;
    scanf("%d",&n);
    vector<ll> a(1000);
    vector<pair<ll,ll>> b;
    ll i,sum=0;
    for(i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
    if(sum==0){
        printf("0");
        return 0;
    }
    sort(a.begin(),a.begin()+n,cmp);
    for(i=0;i<n;i++)printf("%d",a[i]);
}