#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
typedef long long ll;
int main(){
    int n,i;
    cin>>n;
    vector<ll> a(n);
    ll g=0,mx=-1;;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(mx<a[i])mx=a[i];
        g=gcd(a[i],g);
    }
    cout<<((mx/g-n)%2?"Alice":"Bob");
}
