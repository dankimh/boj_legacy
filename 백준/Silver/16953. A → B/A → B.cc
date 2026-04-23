#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    queue<pair<ll,ll>> q;
    q.push({a,1});
    ll min=20000000000;
    while(!q.empty()){
        ll now=q.front().first;
        ll time=q.front().second;
        q.pop();
        if(now==b){
            min=time;
            continue;
        }
        if(now>b)continue;
        if(time>=min)continue;
        if(time+1<=min){
            if(now*2<=b)q.push({now*2,time+1});
            if(now*10+1<=b)q.push({now*10+1,time+1});
        }
    }
    printf("%lld",min<20000000000?min:-1);
}