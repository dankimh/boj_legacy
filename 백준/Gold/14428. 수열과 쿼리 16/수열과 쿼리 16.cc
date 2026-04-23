#include<bits/stdc++.h>
#define ll long long
#define MX 1000000001
#define pii pair<int,int>
using namespace std;
vector<int> a;
pii f(int st,int en,int node,int check,vector<pii> &tree){
    if(st==en)return tree[node-1]={a[st],st};
    int mid=(st+en)/2;
    return tree[node-1]=min(f(st,mid,node*2,check,tree),f(mid+1,en,node*2+1,check,tree));
}
pii findm(int st,int en,int node,int l,int r,int check,vector<pii> &tree){
    if(l>en||r<st)return {MX,-1};
    if(l<=st&&en<=r)return tree[node-1];
    int mid=(st+en)/2;
        pii a=findm(st,mid,node*2,l,r,check,tree);
        pii b=findm(mid+1,en,node*2+1,l,r,check,tree);
        if(a.second==-1)return b;
        else if(b.second==-1)return a;
        else return min(a,b);
}
pii f1(vector<int> &arr,vector<pii> &t,int node,int st,int en,int goal,ll nw){
//printf("s%d %d %d\n",node,st,en);
     if(goal<st||goal>en)return t[node-1];
     if(st==en){arr[goal]=nw;return t[node-1]={nw,goal};}
     int mid=(st+en)/2;
     return t[node-1]=min(f1(arr,t,node*2,st,mid,goal,nw),f1(arr,t,node*2+1,mid+1,en,goal,nw));
}
int main(){
    int n,m;
    scanf("%d",&n);
    a.resize(n);
    vector<pii> ntree(4*n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    f(0,n-1,1,2,ntree);
    for(i=0;i<m;i++){
        int o,p,q;
        scanf("%d %d %d",&o,&p,&q);
        if(o==2){pii ansn=findm(0,n-1,1,p-1,q-1,2,ntree);
        printf("%d\n",ansn.second+1);}
        if(o==1){
            f1(a,ntree,1,0,n-1,p-1,q);
        }
    }
}