#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m,k,s,t,i,j,l;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&s,&t);
    vector<vector<pair<ll,ll>>> mp(n+1);
    vector<vector<ll>> dist(n+1,vector<ll>(k+1,-1));
    for(i=0;i<m;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    for(i=0;i<=k;i++){
        for(j=1;j<=n;j++){
            if(i==0&&j<s)continue;
            else if(i==0&&j==s){dist[j][i]=0;continue;}
            ll mxa=-1,mxb=-1;
            for(auto &l:mp[j]){
                if(l.first<j){
                    //printf("small - %d %d %d\n",dist[l.first][i],l.first,l.second);
                    if(dist[l.first][i]==-1)continue;
                    else mxa=max(mxa,l.second+dist[l.first][i]);
                }
                else if(l.first>j){
                    if(i==0){mxb=-1;continue;}
                    if(dist[l.first][i-1]==-1)continue;

                    else mxb=max(mxb,dist[l.first][i-1]);
                    //printf("big - %d %d %d\n",dist[l.first][i-1],l.first,l.second);
                }
            }
            dist[j][i]=max(mxa,mxb);
        }
    }
    /*for(i=0;i<n+1;i++){
        for(j=0;j<k+1;j++)printf("%d ",dist[i][j]);
        printf("\n");
    }*/
    printf("%lld",dist[t][k]);
}