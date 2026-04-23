#include<bits/stdc++.h>
using namespace std;
vector<int> parent,r;
int f(int u){
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    parent.resize(n+1);
    r.resize(n+1);
    int i,ch=-1;
    for(i=1;i<=n;i++){
        parent[i]=i;
        r[i]=1;
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(f(a)==f(b)&&ch==-1){
            ch=printf("%d",i+1);
        }
        else uni(a,b);
    }
    if(ch==-1)printf("0");
}