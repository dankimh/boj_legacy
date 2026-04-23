/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,i,j;
    cin>>n;
    vector<pair<ll,ll>> gas(n);
    for(i=0;i<n;i++){
        cin>>gas[i].first>>gas[i].second;
    }
    sort(gas.begin(),gas.end());
    ll l,p;
    cin>>l>>p;
    ll ans=0,can=p;
    set<ll,greater<ll>> s;
    for(i=0;i<n;i++){
        if(gas[i].first<=can)s.insert(gas[i].second);
        else{

        }
    }
    while(can<l){
        //cout<<can<<"p\n";
        ll mx=-1,loc=0;
        for(i=n-1;i>=0;i--){
            if(gas[i].first!=-1&&gas[i].second<=can){
                mx=gas[i].first;
                gas[i].first=-1;
                break;
            }
        }
        can+=mx;
        ans++;
    }
    cout<<ans;
}*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,i,j;
    cin>>n;
    vector<pair<ll,ll>> gas(n);
    for(i=0;i<n;i++){
        cin>>gas[i].first>>gas[i].second;
    }
    sort(gas.begin(),gas.end());
    ll l,p;
    cin>>l>>p;
    /*if(l<=p){
        cout<<"0";
        return 0;
    }*/
    ll ans=0,can=p;
    while(can<l){
        //cout<<can<<"p\n";
        ll mx=-1,loc=0;
        for(i=0;i<n;i++){
            if(gas[i].first>can)break;
            if(mx<gas[i].second){
                mx=gas[i].second;
                loc=i;
            }
        }
        if(mx==-1){ans=-1;break;}
        gas[loc].second=-1;
        can+=mx;
        ans++;
    }
    cout<<ans;
}
