#include<stdio.h>
#define min(x,y) ((x<y)?x:y)
int n,w[16][16],vis[16][0xffff];
int dp(int now,int visited){
    if(vis[now][visited])return vis[now][visited];
    if(visited==(1<<n)-1){
        if(w[now][0]==0)return 0xfffffff;
        return w[now][0];
    }
//printf("a%d %d %d\n",now,visited,vis[now][visited]);
    int i;
    vis[now][visited]=0xfffffff;
    for(i=0;i<n;i++){
        //printf("x%d %d %d %d %d\n",w[now][i]!=0,visited,1<<i,visited&(1<<i),w[now][i]!=0&&visited&(1<<i)==0);
        if(w[now][i]!=0&&(visited&(1<<i))==0){
            //int a=dp(i,visited|(1<<i))+w[now][i];
            //printf("x%d %d\n",vis[now][visited],a);
            vis[now][visited]=min(vis[now][visited],dp(i,visited|(1<<i))+w[now][i]);

        }
    }
    return vis[now][visited];
}
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&w[i][j]);
    int ans=dp(0,1);
    printf("%d",ans);
}