#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll n,m;
    cin>>n>>m;
    if(n%2){
        ll ans=(2*m+1)*(m+1);
        for(ll i=1;i<=m;i++){
            ld x=pow((ld)i/(ld)n,1/(ld)(n-1));
            ld imsi=((1.0-1.0/(ld)n)*(ld)i*x);
            ll in=round(imsi);
            ll add=0;
            if((ll)x==x)add=m-in;
            else add=m-(ll)imsi;
            if(in>m)break;
            ans+=2*add;
        }
        cout<<ans;
    }
    else{
        ll ans=0;
        ll mn=(ll)min(pow(((ld)m/(ld)(n-1)),1/(ld)n),pow((ld)m/(ld)n,1/(ld)(n-1)));
        ans=mn*2+1;
        cout<<ans;
    }
}
