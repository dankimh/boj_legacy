#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;
queue< pair<int,int> > a;
int d[5]={1,0,-1,0,1};
char mp[100][100];
int c[100][100];
int main(){
    int n,m,i,j,cnt=1;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",mp[i]);
        for(j=0;j<m;j++)mp[i][j]-='0';
    }
    c[0][0]=1;
    a.push(make_pair(0,0));
    while(!a.empty()){
        int x=a.front().first;
        int y=a.front().second;
        //printf("x: %d y: %d c : %d s : %d\n",x,y,c[x][y],a.size());
        a.pop();
        int p=0;
        for(i=0;i<5;i++){
            if(x+d[i]>=0&&x+d[i]<n&&y+d[i+1]>=0&&y+d[i+1]<m&&c[x+d[i]][y+d[i+1]]==0&&mp[x+d[i]][y+d[i+1]]==1){
                a.push(make_pair(x+d[i],y+d[i+1]));
                c[x+d[i]][y+d[i+1]]=c[x][y]+1;
            }
        }
    }
    //for(i=0;i<n;i++,printf("\n"))for(j=0;j<m;j++)printf("%d ",c[i][j]);
    printf("%d",c[n-1][m-1]);
}