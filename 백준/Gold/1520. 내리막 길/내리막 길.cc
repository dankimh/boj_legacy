#include<bits/stdc++.h>
#define check(x,y) if(x+d[j]<0||x+d[j]>=m||y+d[j+1]<0||y+d[j+1]>=n)continue
#define piii pair<int,pair<int,int>>
using namespace std;
int d[5]={0,1,0,-1,0},dp[500][500];
bool cmp(const piii &a, const piii &b){
    return a.first>b.first;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int i,j,a[500][500];
    vector<piii> seq(m*n);
    for(i=0;i<m;i++)for(j=0;j<n;j++){scanf("%d",&a[i][j]);seq[i*n+j]={a[i][j],{i,j}};}
    sort(seq.begin(),seq.end(),cmp);
    dp[0][0]=1;
    for(i=0;i<m*n;i++){
        int x=seq[i].second.first;
        int y=seq[i].second.second;
        int h=seq[i].first;
    //printf("tt%d %d %d\n",x,y,h);
        for(j=0;j<4;j++){
            check(x,y);
            if(h<a[x+d[j]][y+d[j+1]])dp[x][y]+=dp[x+d[j]][y+d[j+1]];
        }
    }
    printf("%d",dp[m-1][n-1]);
}