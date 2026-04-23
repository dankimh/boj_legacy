#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll MAX=1e6+2;
vector<int> mob(MAX);
vector<int> prime;
bool isp[MAX];
void mo(){
    fill(isp,isp+MAX,true);
    fill(mob.begin(),mob.end(),-1);
    mob[1]=1;
    for(int i=2;i<=MAX;i++){
        if(isp[i])prime.push_back(i);
        for(int p:prime){
            if(i*p>MAX)break;
            isp[i*p]=false;
            if(i%p==0){
                mob[i*p]=0;
                break;
            }
            mob[i*p]=mob[i]*mob[p];
        }
    }
}
ll f(ll n){
    ll ans=0,i;
    for(i=1;i*i<=n;i++){
        ans+=mob[i]*(n/(i*i));
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mo();
    ll a,b,i;
    cin>>a>>b;
    cout<<f(b)-f(a-1);
}