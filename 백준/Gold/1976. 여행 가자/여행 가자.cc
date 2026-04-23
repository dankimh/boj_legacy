#include<bits/stdc++.h>
using namespace std;
int parent[201];
int r[201];
int f(int u){
    if(u==parent[u])return u;
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
    int i;
    for(i=1;i<=n;i++){parent[i]=i;r[i]=1;}
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d",&a);
            if(a==1)uni(i,j);
        }
    }
    int trav[1000];
    for(i=0;i<m;i++)scanf("%d",&trav[i]);
    for(i=1;i<m;i++){
        if(f(trav[i-1])!=f(trav[i])){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}