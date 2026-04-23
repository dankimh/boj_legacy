#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF=1e13;
int main(){
    ll n,e;
    cin>>n>>e;
    ll i,j;
    vector<vector<ll>> mp(n+1),rmp(n+1);
    vector<ll> rsz(n+1,0);
    for(i=0;i<e;i++){
        ll x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        rmp[y].push_back(x);
        rsz[y]++;
    }
    queue<ll> q;
    vector<ll> ch(n+1,0);
    vector<ll> st;
    for(i=1;i<=n;i++){
        if(rsz[i]==0){
            st.push_back(i);
            q.push(i);
            ch[i]=1;
        }
    }

    vector<ll> s;
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        s.push_back(now);
        for(i=0;i<mp[now].size();i++){
            ll next=mp[now][i];
            if(ch[next]==0&&--rsz[next]==0){
                ch[next]=1;
                q.push(next);
            }
        }
    }
    //for(auto& x:s)cout<<x<<" ";
    vector<vector<ll>> dp(2,vector<ll>(n+1,0));//0=J,1=M
    dp[0][s.back()]=0;
    dp[1][s.back()]=INF;
    for(i=s.size()-2;i>=0;i--){
        ll now=s[i];
        //cout<<now<<"x\n";
        for(j=0;j<1;j++){
            ll mn=INF;
            vector<ll> imsi;
            for(ll k=0;k<mp[now].size();k++){
                ll next=mp[now][k];
                imsi.push_back(dp[!j][next]);
                //if(mn>dp[!j][next])mn=dp[!j][next];
            }
            sort(imsi.begin(),imsi.end());
            ll add=0,as=1;
            mn=imsi.back();
            //cout<<mn<<"dd\n";
            for(ll k=imsi.size()-2;k>=0;k--,as++){
                if(imsi[k+1]>imsi[k])add=as;
                mn=min(mn,as+imsi[k]);
            }
            dp[j][now]=mn;
            /*int cnt=0;
            for(int k=0;k<mp[now].size();k++){
                int next=mp[now][k];
                if(dp[!j][next]==mn)cnt++;
            }
            dp[j][now]=mn+mp[now].size()-cnt;*/
            //cout<<dp[j][now]<<" ";
        }
        for(j=1;j<2;j++){
            ll mn=INF;
            for(ll k=0;k<mp[now].size();k++){
                ll next=mp[now][k];
                if(mn>dp[!j][next])mn=dp[!j][next];
            }
            dp[j][now]=mn;
            //cout<<dp[j][now]<<" ";
        }
        //cout<<"\n";

    }
    ll ans=INF;
    for(auto& x:st){
        ans=min(ans,dp[0][x]);
    }
    if(ans!=INF)cout<<ans;
    else cout<<"-1";
}

