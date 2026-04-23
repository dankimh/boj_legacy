#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a;
int f(int st,int en,int node,int check,vector<int> &tree){
    if(st==en)return tree[node-1]=a[st];
    int mid=(st+en)/2;
    if(check==1)return tree[node-1]=max(f(st,mid,node*2,check,tree),f(mid+1,en,node*2+1,check,tree));
    else if(check==2)return tree[node-1]=min(f(st,mid,node*2,check,tree),f(mid+1,en,node*2+1,check,tree));
}
int findm(int st,int en,int node,int l,int r,int check,vector<int> &tree){
    if(l>en||r<st)return -1;
    if(l<=st&&en<=r)return tree[node-1];
    int mid=(st+en)/2;
    if(check==1){
        return max(findm(st,mid,node*2,l,r,check,tree),findm(mid+1,en,node*2+1,l,r,check,tree));
    }
    else if(check==2){
        int a=findm(st,mid,node*2,l,r,check,tree);
        int b=findm(mid+1,en,node*2+1,l,r,check,tree);
        if(a==-1)return b;
        else if(b==-1)return a;
        else return min(a,b);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    a.resize(n);
    vector<int> xtree(4*n,0);
    vector<int> ntree(4*n,0);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    f(0,n-1,1,1,xtree);
    f(0,n-1,1,2,ntree);
    for(i=0;i<m;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        int ansx=findm(0,n-1,1,p-1,q-1,1,xtree);
        int ansn=findm(0,n-1,1,p-1,q-1,2,ntree);
        printf("%d\n",ansn);
    }
}