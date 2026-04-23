#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int f(int u){
    if(u==-1)return -1;
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    parent[u]=v;
    return;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    parent.resize(n+1);

    int t,tr[50],i,j,ans=m,b[50][50],a[50];
    for(i=0;i<=n;i++)parent[i]=i;
    scanf("%d",&t);
    for(i=0;i<t;i++){scanf("%d",&tr[i]);}
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
        int ch=0;
        scanf("%d",&b[0][i]);
        for(j=1;j<a[i];j++){
            scanf("%d",&b[j][i]);
            uni(b[j][i],b[0][i]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<t;j++){
            if(f(b[0][i])==f(tr[j])){
                ans--;
                break;
            }
        }
    }
    printf("%d",ans);
}