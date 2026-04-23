#include<stdio.h>
#include<stdlib.h>
int post[100000];
int in[100000];
int pre[100000];
int cnt,n;
void f(int stloc,int enloc,int st,int en){
    if(st>en)return;
    //_sleep(100);
    int node=post[en];
    pre[cnt]=node;
    cnt++;
    //printf("d%d %d %d %d %d\n",stloc,enloc,st,en,node);
    if(st==en)return;
    int i;
    for(i=stloc;i<=enloc;i++){
        if(in[i]==node)break;
    }
    f(stloc,i-1,st,st+(i-stloc)-1);
    f(i+1,enloc,st+(i-stloc),en-1);
    return;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    for(i=0;i<n;i++)scanf("%d",&post[i]);
    f(0,n-1,0,n-1);
    for(i=0;i<n;i++)printf("%d ",pre[i]);
}