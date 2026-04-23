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
    else if(p==0){
        if(q<0){
            q=-q;
            r=-r;
        }
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
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
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        if((max(a[0],a[1])<min(a[2],a[3])||min(a[0],a[1])>max(a[2],a[3]))){
            return 0;
        }

    }
    return 1;
}
ll solve(vector<pair<ll,ll>> a){
    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        return 0;
    }
    ll ch2=f(b);
    if(!ch2){
        return 0;
    }
    return 1;
}
ll in(pair<ll,ll> line, vector<pair<ll,ll>> a){
    ll minx=min(a[0].first,a[2].first);
    ll maxx=max(a[0].first,a[2].first);
    ll miny=min(a[0].second,a[2].second);
    ll maxy=max(a[0].second,a[2].second);

    if(line.first>=minx&&line.first<=maxx){
        if(line.second>=miny&&line.second<=maxy)return 1;
    }
    return 0;
}
//ifstream iin;

void answer(){
    //vector<pair<ll,ll>> a(4);
    ll i,j;

    //for(i=0;i<4;i++)scanf("%lld %lld",&a[i].first,&a[i].second);
    vector<pair<ll,ll>> line(4);
    for(i=2;i<4;i++)cin>>line[i].first>>line[i].second;//scanf("%lld %lld",&line[i].first,&line[i].second);
    vector<pair<ll,ll>> a(4);
    cin>>a[0].first>>a[0].second>>a[2].first>>a[2].second;
    //scanf("%lld %lld %lld %lld",&a[0].first,&a[0].second,&a[2].first,&a[2].second);
    a[1].first=a[0].first;a[1].second=a[2].second;
    a[3].first=a[2].first;a[3].second=a[0].second;


    //for(i=0;i<4;i++)printf("aa - %lld %lld\n",a[i].first,a[i].second);
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            line[j]=a[(i+j)%4];
        }
        /*for(j=0;j<4;j++){
            printf("x%d - %lld %lld\n",i,line[j].first,line[j].second);
        }*/
        if(solve(line)==1){
            printf("T\n",i);
            return;
        }
    }
    if(in(line[2],a)==1&&in(line[3],a)==1){
        printf("T\n");
        return;
    }
    printf("F\n");
}
int main(){
    int t;
    //iin.open("in.txt");
    cin>>t;
    while(t--){
        answer();
    }

}