#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll a,ll b){
    ll a2=0,a3=0,ex=a;
    while(ex%2==0){
        ex/=2;
        a2++;
    }
    ex=a;
    while(ex%3==0){
        ex/=3;
        a3++;
    }
    ll b2=0,b3=0;
    ex=b;
    while(ex%2==0){
        ex/=2;
        b2++;
    }
    ex=b;
    while(ex%3==0){
        ex/=3;
        b3++;
    }
    if(a3>b3)return true;
    else{
        if(a2<b2)return true;
    }
    return false;
}
int main(){
    ll n,i;
    scanf("%lld",&n);
    ll a[100];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n,cmp);
    for(i=0;i<n;i++){
        printf("%lld ",a[i]);
    }
}
