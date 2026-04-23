#include<stdio.h>
#include<string.h>
#define bzero(x,y) memset(x,0,y)
int v[501];
int mp[501][501];
int ch=1,n;
int f(int node,int prev){
    //printf("c%d %d %d\n",node,prev,ch);
    v[node]=1;
    int i;
    int r=1;
    for(i=1;i<=n;i++){
        if(i==node)continue;
        if(mp[node][i]==1){
            if(v[i]==0){
                if(!f(i,node))r=0;
            }
            else{
                if(i!=prev)r=0;
            }
        }
    }
    return r;
}
int main(){
    int j=1;
    while(1){
        int m,i,c=0;
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        bzero(v,sizeof(int)*501);
        bzero(mp,sizeof(int)*251001);
        for(i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            mp[a][b]=1;
            mp[b][a]=1;
        }
        for(i=1;i<=n;i++){
            ch=1;
            if(!v[i]){c+=f(i,0);}

        }
        if(c==0)printf("Case %d: No trees.\n",j);
        if(c==1)printf("Case %d: There is one tree.\n",j);
        if(c>1)printf("Case %d: A forest of %d trees.\n",j,c);
        j++;
    }
}
