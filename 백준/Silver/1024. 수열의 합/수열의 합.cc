#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF=1e18;
int main(){
    ll n,l;
    cin>>n>>l;
    for(ll i=l;i<101;i++){
        if((n*2)%i==0){
            ll d=(n*2)/i;
            d=d-i-1;
            if(d%2)continue;
            else{
                bool cond=false;
                for(ll j=0;j<i;j++){
                    if(j+1+d/2<0){
                        cond=true;
                        break;
                    }
                    cout<<j+1+d/2<<" ";
                }
                if(cond)continue;
                cout<<"\n";
                return 0;
            }
        }
    }
    cout<<"-1";
}