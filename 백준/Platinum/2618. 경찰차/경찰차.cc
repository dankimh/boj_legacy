#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010]={0,};
int timeline[1010][1010];
int dist(pair<int,int> a,pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>> c(w);
    int i,j;
    for(i=0;i<w;i++){
        cin>>c[i].first>>c[i].second;
    }
    for(i=1;i<=w;i++){
        dp[i][w]=dp[w][i]=0;
    }
    for(i=w-1;i>=0;i--){
        for(j=w-1;j>=0;j--){
            if(i==j&&i!=0)continue;
            int k=max(i,j)+1;
            pair<int,int> x,y;
            if(i==0)x={1,1};
            else x=c[i-1];
            if(j==0)y={n,n};
            else y=c[j-1];
            int aa=dp[k][j]+dist(x,c[k-1]);
            int bb=dp[i][k]+dist(y,c[k-1]);
            dp[i][j]=min(aa,bb);
            if(aa<bb){
                timeline[i][j]=1;
            }
            else timeline[i][j]=2;
            /*for(int a=0;a<=w;a++){
                for(int s=0;s<=w;s++)cout<<dp[a][s]<<" ";
                cout<<"\n";
            }
            cout<<"\n";*/
        }
    }
    /*for(i=0;i<=w;i++){
        for(j=0;j<=w;j++)cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/
    cout<<dp[0][0]<<"\n";
    int a=0,b=0;
    for(i=1;i<=w;i++){
        if(timeline[a][b]==1){
            cout<<"1\n";
            a=i;
        }
        else{
            cout<<"2\n";
            b=i;
        }
    }
}