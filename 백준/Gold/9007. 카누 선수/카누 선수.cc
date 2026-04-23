#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>& f(vector<vector<ll>>& w,ll n,vector<ll>& s){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s.push_back(w[0][i]+w[1][j]);
        }
    }
    sort(s.begin(),s.end());
    return s;
}
void solve(){
    ll k,n;
    cin>>k>>n;
    vector<vector<ll>> w1(2,vector<ll>(n)),w2(2,vector<ll>(n));
    ll i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++)cin>>w1[i][j];
    }
    for(i=0;i<2;i++){
        for(j=0;j<n;j++)cin>>w2[i][j];
    }
    vector<ll> v1,v2;
    v1=f(w1,n,v1);
    v2=f(w2,n,v2);
    ll mn=LLONG_MAX,val=0,realmn=0;
    for(auto it=v1.begin();it!=v1.end();++it){
        auto it2=lower_bound(v2.begin(),v2.end(),k-*it);
        if(it2!=v2.end()){
            if(mn>abs(k-*it-*it2)){
                mn=abs(k-*it-*it2);
                realmn=(k-*it-*it2);
                val=*it+*it2;
            }
            else if(mn==abs(k-*it-*it2)){
                if(realmn<(k-*it-*it2)){
                    realmn=(k-*it-*it2);
                    val=*it+*it2;
                }
            }
        }
        if(it2!=v2.begin()){
            --it2;
            if(mn>abs(k-*it-*it2)){
                mn=abs(k-*it-*it2);
                realmn=(k-*it-*it2);
                val=*it+*it2;
            }
            else if(mn==abs(k-*it-*it2)){
                if(realmn<(k-*it-*it2)){
                    realmn=(k-*it-*it2);
                    val=*it+*it2;
                }
            }
        }
    }
    cout<<val<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
