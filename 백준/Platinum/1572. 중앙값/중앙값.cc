#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void erase_val(multiset<ll>& s, ll val){
    auto it=s.find(val);
    //cout<<distance(s.begin(),it)<<"aa\n";
    s.erase(it);
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    ll i,ans=0;
    multiset<ll> s;
    vector<ll> a(n);
    for(i=0;i<k;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    auto median_it=s.begin();
    advance(median_it,(k+1)/2-1);
    ans+=*(median_it);
    //cout<<*median_it<<"s\n";
    for(;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
        if(a[i]>=*median_it){
            if(k%2==0)++median_it;
        }
        else{
            if(k%2)--median_it;
        }
        //erase_val(s,a[i-k]);
        if(a[i-k]>*median_it){
            if(k%2==0)--median_it;
        }
        else if(a[i-k]==*median_it){
            if(k%2)++median_it;
            else{
                if(*prev(median_it,1)!=*median_it)--median_it;
            }
        }
        else if(a[i-k]<*median_it){
            if(k%2)++median_it;
        }
        erase_val(s,a[i-k]);
        ans+=*(median_it);
        //cout<<a[i-k]<<" "<<*median_it<<"s\n";
    }
    cout<<ans;
}