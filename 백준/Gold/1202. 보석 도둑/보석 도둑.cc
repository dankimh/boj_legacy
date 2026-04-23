#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll i;
    vector<pair<ll,ll>> jew(n);
    vector<ll> bag(k);
    for(i=0;i<n;i++)scanf("%lld %lld",&jew[i].first,&jew[i].second);
    sort(jew.begin(),jew.begin()+n);
    for(i=0;i<k;i++)scanf("%lld",&bag[i]);
    sort(bag.begin(),bag.begin()+k);
    priority_queue<pair<ll,ll>> q;
    ll j=0;
    ll sum=0;
    if(bag[k-1]<jew[0].first){
        printf("0");
        exit(0);
    }
    for(i=0;i<k;i++){
        //
        for(;j<n;j++){

            if(jew[j].first>bag[i]){break;}
        //printf("ddd%d\n",j);
            q.push({jew[j].second,jew[j].first});
        }
        //printf("eeee%d\n",q.size());
        if(q.size()!=0){
        sum+=(ll)q.top().first;
        q.pop();
        }
    }
    printf("%lld",sum);
}