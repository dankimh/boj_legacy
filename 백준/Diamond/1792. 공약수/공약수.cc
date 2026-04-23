#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> mob(50001);
vector<int> mobs(50001);
vector<int> prime;
bool isp[50001];
void mo(){
    fill(isp,isp+50001,true);
    fill(mob.begin(),mob.end(),-1);
    mob[1]=1;
    for(int i=2;i<=50000;i++){
        if(isp[i])prime.push_back(i);
        for(int p:prime){
            if(i*p>50000)break;
            isp[i*p]=false;
            if(i%p==0){
                mob[i*p]=0;
                break;
            }
            mob[i*p]=mob[i]*mob[p];
        }
    }
    mobs[1]=mob[1];
    for(int i=2;i<=50000;i++){
        mobs[i]=mob[i]+mobs[i-1];
    }
}
void solve(){
    ll a,b,d,i,j,ans=0;
    cin>>a>>b>>d;
    a=a/d;
    b=b/d;
    ll sz=min(a,b);
    for(i=1;i<=sz;i=j+1){
        j=min(a/(a/i),b/(b/i));
        ans+=(a/i)*(b/i)*(mobs[j]-mobs[i-1]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt,sum=0;
    mo();
    cin>>tt;
    while(tt--)solve();
}