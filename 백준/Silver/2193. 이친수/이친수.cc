#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,z[90]={1,},o[90]={1,},i;
    scanf("%lld",&n);
    for(i=1;i<n;i++){
        z[i]=z[i-1]+o[i-1];
        o[i]=z[i-1];
    }
    printf("%lld",o[n-1]);
}