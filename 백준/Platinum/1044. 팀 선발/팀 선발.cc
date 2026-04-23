#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void print(tuple<ll,ll,ll> x){
    cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x);
    cout<<"asdf\n";
}
int main(){
    ll n,i,j;
    cin>>n;
    vector<vector<ll>> a(2,vector<ll>(n/2)),b(2,vector<ll>(n/2));
    vector<vector<pair<ll,ll>>> fr(20),re(20);
    for(i=0;i<2;i++)for(j=0;j<n/2;j++)cin>>a[i][j];
    for(i=0;i<2;i++)for(j=0;j<n/2;j++)cin>>b[i][j];
    for(int l=0;l<2;l++){
        for(i=0;i<(1<<(n/2));i++){
            bitset<18> x(i);
            ll imsi=0,k=0;
            for(j=n/2-1;j>=0;j--,k++){
                if(x[j])imsi+=b[l][k];
                else imsi-=a[l][k];
            }
            if(l==0)fr[x.count()].push_back({(imsi),i});
            else re[n/2-x.count()].push_back({-(imsi),i});
        }
    }
    tuple<ll,ll,ll> mn={LLONG_MAX,LLONG_MAX,LLONG_MAX};
    ll loc=0;
    for(i=0;i<=n/2;i++){
        sort(fr[i].begin(),fr[i].end());
        sort(re[i].begin(),re[i].end());
        for(j=0;j<fr[i].size();j++){
            pair<ll,ll> val=fr[i][j];
            pair<ll,ll> cmp={val.first,0};
            auto it=lower_bound(re[i].begin(),re[i].end(),cmp);
            tuple<ll,ll,ll> x;
            if(it!=re[i].end()){
                x={abs((*it).first-val.first),val.second,(*it).second};
                if(mn>x)mn=x;
            }
            if(it!=re[i].begin()){
                auto as=*(it-1);
                pair<ll,ll> cmp2={as.first,0};
                auto it2=lower_bound(re[i].begin(),re[i].end(),cmp2);
                x={abs((*it2).first-val.first),val.second,(*it2).second};
                if(mn>x)mn=x;
            }
        }
    }
    ll ms=1<<(n/2-1);
    loc=get<1>(mn);
    for(i=0;i<n/2;i++){
        if(loc/ms)cout<<"2 ";
        else cout<<"1 ";
        loc%=ms;
        ms>>=1;
    }
    ms=1<<(n/2-1);
    loc=get<2>(mn);
    for(i=0;i<n/2;i++){
        if(loc/ms)cout<<"2 ";
        else cout<<"1 ";
        loc%=ms;
        ms>>=1;
    }
}

