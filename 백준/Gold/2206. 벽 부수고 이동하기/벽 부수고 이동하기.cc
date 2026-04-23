#include<stdio.h>
#include<queue>

using namespace std;
int cnt;
int n,m;
char a[10002][10002];
int b[1000][1000][2];
int dir[5]={1,0,-1,0,1};
int main(){
    scanf("%d %d\n",&n,&m);
    int i,j;
    queue<pair<pair<pair<int,int>,int>,int>> q;
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    int x,y,c;
    q.push(make_pair(make_pair(make_pair(0,0),1),1));
    b[0][0][1]=1;
    while(!q.empty()){
        x=q.front().first.first.first;
        y=q.front().first.first.second;
        c=q.front().first.second;
        cnt=q.front().second;
        //b[x][y][c]=1;
        if(x==n-1&&y==m-1)break;
        //printf("%d %d %d %d\n",x,y,c,cnt);
        q.pop();
        for(i=0;i<4;i++){

            if(x+dir[i]<0||x+dir[i]>n-1||y+dir[i+1]<0||y+dir[i+1]>m-1)continue;
            if(c==0){
                if(!b[x+dir[i]][y+dir[i+1]][0]&&a[x+dir[i]][y+dir[i+1]]=='0'){
                    q.push(make_pair(make_pair(make_pair(x+dir[i],y+dir[i+1]),c),cnt+1));
                    b[x+dir[i]][y+dir[i+1]][0]=1;
                }
            }
            if(c==1){
                if(!b[x+dir[i]][y+dir[i+1]][1]&&a[x+dir[i]][y+dir[i+1]]=='0'){
                    q.push(make_pair(make_pair(make_pair(x+dir[i],y+dir[i+1]),c),cnt+1));
                    b[x+dir[i]][y+dir[i+1]][1]=1;
                }
                if(!b[x+dir[i]][y+dir[i+1]][1]&&a[x+dir[i]][y+dir[i+1]]=='1'){
                    q.push(make_pair(make_pair(make_pair(x+dir[i],y+dir[i+1]),0),cnt+1));
                    b[x+dir[i]][y+dir[i+1]][1]=1;
                }
            }
        }
    }
    if(x!=n-1||y!=m-1)printf("-1");
    else printf("%d",cnt);
}