#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,i,ans=0;
    stack<pair<ll,ll>> s;
    cin>>n;
    for(i=0;i<n;i++){
        ll a;
        cin>>a;
        if(s.size()==0)s.push({a,1});
        else{
            if(s.top().first==a){
                ans+=(s.top().second);
                if(s.size()>1)ans++;
                ll x=s.top().second;
                s.pop();
                s.push({a,x+1});
            }
            else if(s.top().first>a){
                ans++;
                s.push({a,1});
            }
            else{
                while(!s.empty()&&s.top().first<a){
                    ans+=(s.top().second);
                    s.pop();

                }
                if(!s.empty()){
                    if(s.top().first>a){
                        ans++;
                        s.push({a,1});
                    }
                    else if(s.top().first==a){
                        ans+=(s.top().second);
                        if(s.size()>1)ans++;
                        ll x=s.top().second;
                        s.pop();
                        s.push({a,x+1});
                    }
                }
                else{
                    s.push({a,1});
                }
            }
        }
        //cout<<i<<" "<<ans<<"\n";
    }
    cout<<ans;
}