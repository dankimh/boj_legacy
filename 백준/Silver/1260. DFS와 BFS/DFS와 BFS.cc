#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
//stack<int>s;
queue<int>q;
int c[1001][1001],d[1001],e[1001];
int n,m;
void dfs(int v){
    int i;
    d[v]=1;
    printf("%d ",v);
    for(i=1;i<=n;i++){
        if(c[v][i]==1&&d[i]==0)dfs(i);
    }
    return;
}
int main(){
    int v,i,a,b;
    scanf("%d %d %d",&n,&m,&v);
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        c[a][b]=1;
        c[b][a]=1;
    }
    dfs(v);
    printf("\n");
    e[v]=1;
    q.push(v);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        printf("%d ",x);
        for(i=1;i<=n;i++){
            if(c[x][i]==1&&e[i]==0){
                e[i]=1;
                q.push(i);
            }
        }
    }
}