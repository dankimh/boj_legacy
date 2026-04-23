#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> frr,ree;
vector<ll> fr,re;
void f(ll n,string a,vector<ll> ch){
    ll siz;
    siz=a=="fr"?(ll)fr.size():(ll)re.size();
    if(n==siz){

        ll i,sum=0,check=0;
        /*for(i=0;i<n;i++)check+=ch[i];
        if(check==0)return;*/
        //if(check==20)cout<<n<<'-'<<a<<' '<<check<<"\n";
        if(a=="fr"){
            for(i=0;i<n;i++){
                if(ch[i]==1)sum+=fr[i];
            }
            frr.push_back(sum);
        }
        else if(a=="re"){
            for(i=0;i<n;i++){
                if(ch[i]==1)sum+=re[i];
            }
            ree.push_back(sum);
        }
        return;
    }
    ch.push_back(0);
    f(n+1,a,ch);
    ch[n]=1;
    f(n+1,a,ch);
    return;
}
bool cmp(ll a,ll b){return a>b;};
int main(){
    ll n,s;
    scanf("%lld %lld",&n,&s);

    ll i,j;
    for(i=0;i<n/2;i++){
        ll a;
        scanf("%lld",&a);
        fr.push_back(a);
    }
    for(i=n/2;i<n;i++){
        ll a;
        scanf("%lld",&a);
        re.push_back(a);
    }
    vector<ll> ch;
    f(0,"fr",ch);
    ch.clear();



    f(0,"re",ch);
    sort(frr.begin(),frr.end());
    sort(ree.begin(),ree.end());
    /*for(auto &i:frr)printf("%d ",i);
    printf("\n");
    for(auto &i:ree)printf("%d ",i);
    printf("\n");*/
    ll ans=0;
    i=0,j=0;
    for(i=0;i<(ll)frr.size();i++){
        ll frnow=lower_bound(ree.begin(),ree.end(),s-frr[i])-ree.begin();
        ll renow=upper_bound(ree.begin(),ree.end(),s-frr[i])-ree.begin();
        //printf("%lld %lld %lld\n",frnow,renow,frr[i]);
        ans+=renow-frnow;
    }
    printf("%lld",s==0?ans-1:ans);
}