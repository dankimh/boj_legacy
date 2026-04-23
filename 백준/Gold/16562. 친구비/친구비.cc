#include<bits/stdc++.h>
using namespace std;
vector<int> parent,money;
int f(int u){
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(money[u]<money[v])parent[v]=u;
    else parent[u]=v;
    return;
}
int main(){
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);
    vector<int> ch(n+1,0);
    parent.resize(n+1);
    money.resize(n+1);
    for(i=1;i<=n;i++){
        scanf("%d",&money[i]);
        parent[i]=i;
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        uni(a,b);
    }
    int charge=0;
    for(i=1;i<=n;i++){
        if(ch[f(i)]==0){
            charge+=money[f(i)];
            ch[f(i)]=1;
        }
    }
    if(charge<=k)printf("%d",charge);
    else printf("Oh no");
}