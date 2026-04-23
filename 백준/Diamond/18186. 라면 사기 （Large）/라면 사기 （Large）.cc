#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,c;
/*ll f(vector<ll>& a,ll val){
    ll i,j,ans=0;
    for(i=0;i<n-val;i++){
        ll mn=1010101;
        for(j=0;j<=val;j++){
            mn=min(mn,a[i+j]);
        }
        ans+=(mn*(b+c*val));
        for(j=0;j<=val;j++){
            a[i+j]-=mn;
        }
    }
    return ans;
}*/
void solve(){
    ll n;
    cin>>n>>b>>c;
    ll i,sum=0,j;
    vector<ll> a(n);
    for(i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    if(b<=c){cout<<sum*b;return;}
    ll ans=0;
    //ans+=f(a,2);
    for(i=0;i<n-2;i++){
        if(a[i]==0)continue;
        if(a[i]>a[i+1]){
            //cout<<"1\n";
            ans+=(a[i]-a[i+1])*b;
            a[i]=a[i+1];
            i--;
            continue;
        }
        if(a[i+1]>a[i+2]){
            //cout<<"2\n";
            ll x=min(a[i],a[i+1]-a[i+2]);
            ans+=(b+c)*(x);
            a[i]-=x;
            a[i+1]-=x;
            i--;
            continue;
        }
        //cout<<"3\n";
        ll mn=a[i];
        ans+=mn*(b+c*2);
        for(j=0;j<3;j++){
            a[i+j]-=mn;
        }
    }
    /*for(i=0;i<n;i++){cout<<a[i]<<" ";}
    cout<<"1\n";*/
    for(i=0;i<n-1;i++){
        ll mn=min(a[i],a[i+1]);
        ans+=mn*(b+c);
        for(j=0;j<2;j++){
            a[i+j]-=mn;
        }
    }
    /*for(i=0;i<n;i++){cout<<a[i]<<" ";}
    cout<<"2\n";*/
    for(i=0;i<n;i++){
        ll mn=a[i];
        ans+=(mn*(b));
        a[i]-=mn;
    }
    /*for(i=0;i<n;i++){cout<<a[i]<<" ";}
    cout<<"3\n";*/
    cout<<ans;
}
int main(){
    int t=1;
    while(t--)solve();
}
