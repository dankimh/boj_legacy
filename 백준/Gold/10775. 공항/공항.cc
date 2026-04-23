#include<bits/stdc++.h>
using namespace std;
vector<int> parent,r;
int f(int u){
    if(u==-1)return -1;
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    //if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    //if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    int g,p;
    scanf("%d %d",&g,&p);
    vector<int> gi(g);
    int i,ans=0,ch=-1;
    parent.resize(g+1);
    r.resize(g+1);
    for(i=0;i<=g;i++){
        parent[i]=i;
        r[i]=1;
    }
    //parent[0]=0;
    //parent[1]=0;
    for(i=0;i<p;i++){
        scanf("%d",&gi[i]);
        if(ch!=-1)continue;
        if(f(gi[i])==0){
            ch=printf("%d",ans);
        }
        else {uni(gi[i],f(gi[i])-1);ans++;}
    }
    if(ch==-1)printf("%d",ans);
}