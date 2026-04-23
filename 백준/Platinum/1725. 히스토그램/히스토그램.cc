#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#define ll long long
using namespace std;
void g(vector<int> &his,vector<int> &segtree,int node,int st,int en){

    if(st==en){segtree[node-1]=st;return;}
    g(his,segtree,node*2,st,(st+en)/2);
    g(his,segtree,node*2+1,(st+en)/2+1,en);
    if(his[segtree[node*2-1]]<=his[segtree[node*2+1-1]])segtree[node-1]=segtree[node*2-1];
    else segtree[node-1]=segtree[node*2+1-1];
    /*if(a.first<b.first){
        return segtree[node-1]=a;
    }
    else if(a.first==b.first){
        if(a.second<b.second)return segtree[node-1]=a;
        else return segtree[node-1]=b;
    }*/
}
int h(vector<int> &his,vector<int> &segtree,int node,int st,int en,int start,int end){
    //printf("h%d %d %d\n",node,st,en);
    if(en<start)return -1;
    if(end<st)return -1;
    if(start<=st&&en<=end)return segtree[node-1];
    int a,b;
    a=h(his,segtree,node*2,st,(st+en)/2,start,end);
    b=h(his,segtree,node*2+1,(st+en)/2+1,en,start,end);
    if(a==-1)return b;
    else if(b==-1)return a;
    else{
        if(his[a]<=his[b]){
            return a;
        }
        else return b;
    }
}
ll f(vector<int> &his,vector<int> &segtree,int st,int en,int n){

    if(st>en){
        return -1;
    }
    if(st==en){
        return his[st];
    }
    //ll min=1000000001,loc=0,i;
    int m;
    m=h(his,segtree,1,0,n-1,st,en);
    //printf("m%d %d\n",m,his[m]);
    ll a=0,b,c=0;
    if(st<=m-1)a=f(his,segtree,st,m-1,n);
    if(m+1<=en)c=f(his,segtree,m+1,en,n);
    //b=f(his,i,i);

    ll result=0;
    if(a<c)result=c;
    else result=a;
    if(result<((ll)his[m]*(ll)(en-st+1)))result=(ll)his[m]*(ll)(en-st+1);
    /*result=max(a.first,c.first);
    result=max(result,(ll)his[m]*(ll)(en-st+1));*/
    return result;
}
int main(){
  
        int n;
        scanf("%d",&n);
     
        int i;
        vector<int> his(100000);
        vector<int> segtree(300000);
        for(i=0;i<n;i++)scanf("%d",&his[i]);
        g(his,segtree,1,0,n-1);
        //for(i=0;i<15;i++)printf("seg%d\n",segtree[i]);
        ll ans;
        //ans=g(his,0,n-1);
        ans=f(his,segtree,0,n-1,n);
        printf("%lld\n",ans);
  
}