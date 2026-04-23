#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    //printf("%d %d %d %d\n",p,q,r,g);
    if(g==0)g=1;
    ans[0]=p/g;
    ans[1]=q/g;
    ans[2]=r/g;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
int f(vector<pair<ll,ll>> a){
    auto ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    auto ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans4=change(a[2],a[3]);
    //for(i=0;i<3;i++)printf("%lld %lld\n",ans1[i],ans4[i]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        //printf("in\n");
        if((max(a[0].first,a[1].first)<min(a[2].first,a[3].first)||min(a[0].first,a[1].first)>max(a[2].first,a[3].first))){
            return 0;
        }
        if(max(a[0].second,a[1].second)<min(a[2].second,a[3].second)||min(a[0].second,a[1].second)>max(a[2].second,a[3].second))return 0;
    }
    return 1;
}
int main(){
    vector<pair<ll,ll>> a(4);
    ll i;
    for(i=0;i<4;i++)scanf("%lld %lld",&a[i].first,&a[i].second);

    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        printf("0");
        exit(0);
    }
    ch1=f(b);
    if(!ch1){
        printf("0");
        exit(0);
    }

    printf("1");
}