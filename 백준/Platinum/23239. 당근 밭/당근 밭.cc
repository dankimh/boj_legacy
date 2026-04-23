#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll w,h,l,ans=0,i;
    cin>>w>>h>>l;
    ll a=0;
    for(i=1;i<=l;i++){
        ll y=(ll)((double)sqrt((double)(l*l-i*i)));
        a+=y;
    }
    ans+=(3*a);
    ans+=l;
    ans+=l;
    if(l>w){
        ans+=(l-w);
        ll b=0;
        for(i=1;i<=(l-w);i++){
            ll y=(ll)((double)sqrt((double)((l-w)*(l-w)-i*i)));
            b+=y;
        }
        ans+=b;
    }
    if(l>h){
        ans+=(l-h);
        ll c=0;
        for(i=1;i<=(l-h);i++){
            ll y=(ll)((double)sqrt((double)((l-h)*(l-h)-i*i)));
            c+=y;
        }
        ans+=c;
    }
    if(l>w+h){
        ll d=0;
        for(i=1;i<=(l-w-h);i++){
            ll y1=(ll)((double)sqrt((double)((l-h)*(l-h)-(i+w)*(i+w))));
            ll y2=(ll)((double)sqrt((double)((l-w)*(l-w)-(i)*(i))))-h;
            d+=min(y1,y2);
        }
        ans-=d;
    }
    cout<<ans;
}