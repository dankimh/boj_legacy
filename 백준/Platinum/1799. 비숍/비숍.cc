#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define ch(x,y,j) if(x+d[j]<0||x+d[j]>=n||y+d[j+1]<0||y+d[j+1]>=n)continue;
using namespace std;
int mxw=0,mxb=0,d[5]={0,1,0,-1,0};
void f(int x,int y,vvi vi,int cnt,int wb){
    //printf("x--%d %d %d\n",x,y,cnt);
    vi[x][y]=2;
    int i,j,k;
    int n=vi.size();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==x&&j==y)continue;
            if(i+j==x+y)vi[i][j]=0;
            if(i-j==x-y)vi[i][j]=0;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i*n+j<x*n+y)continue;
            if(vi[i][j]==wb)f(i,j,vi,cnt+1,wb);
        }
    }
    /*printf("x-%d\n",cnt);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",vi[i][j]);
        }
        printf("\n");
    }*/
    if(wb==1){
        if(mxw<cnt)mxw=cnt;
    }
    else if(mxb<cnt)mxb=cnt;
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    vvi mp(n,vector<int> (n,0));
    vvi vi(n,vector<int> (n,0));
    int t=1;
    int i,j;
    for(i=0;i<n;i++){
        int imsi=t;
        for(j=0;j<n;j++){
            vi[i][j]=imsi;
            imsi=-imsi;
        }
        t=-t;
    }

    for(i=0;i<n;i++)for(j=0;j<n;j++){scanf("%d",&mp[i][j]);if(mp[i][j]==0)vi[i][j]=0;}
    //for(i=0;i<n;i++,printf("\n"))for(j=0;j<n;j++)printf("%d ",vi[i][j]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mp[i][j]==1){
                if(vi[i][j]==1)f(i,j,vi,1,1);
                else f(i,j,vi,1,-1);
            }
        }
    }
    printf("%d",mxw+mxb);
}