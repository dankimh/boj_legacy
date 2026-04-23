#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    vector<ll> cnt(10,0);
    vector<vector<ll>> imsi(12,vector<ll>(10,0));
    scanf("%lld",&n);
    ll m=n;
    int i;
    for(i=1;i<10;i++){
        imsi[1][i]=1;
    }
    ll q=10;
    for(i=2;i<12;i++){
        for(int j=0;j<10;j++){
            ll mul=imsi[i-1][j];
            if(j==0)mul=imsi[i-1][1];
            imsi[i][j]=mul*9;
            imsi[i][j]+=imsi[i-1][j];
            if(j!=0)imsi[i][j]+=q;
        }
        q*=10;
    }
    imsi[1][0]=0;
    ll a=1,b=0;
    while(n>0){
        if(n/10!=0){
        int x=n%10;
        for(i=0;i<10;i++){
            int mul=imsi[b][i];
            if(i==0)mul=imsi[b][1];
            cnt[i]+=(mul*x);
        }
        for(i=0;i<x;i++){
            cnt[i]+=a;
        }
        cnt[x]+=(m%a+1);
        }
        else{
            int x=n%10;
        for(i=0;i<10;i++){
            int mul=imsi[b][i];
            if(i==0)mul=imsi[b][1];
            cnt[i]+=(mul*(x-1));
            cnt[i]+=imsi[b][i];
        }
        for(i=1;i<x;i++){
            cnt[i]+=a;
        }
        cnt[x]+=(m%a+1);
        }
        a*=10;
        b++;
        n/=10;
    }
    for(i=0;i<10;i++)printf("%lld ",cnt[i]);
}