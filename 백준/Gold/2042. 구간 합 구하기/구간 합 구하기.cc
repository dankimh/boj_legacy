#include<stdio.h>
#include<vector>
#include<math.h>
#define ll long long
#define vll vector<ll>
using namespace std;
ll f(vll &arr,vll &t,int node,int st,int en){

    if(st==en){
        return t[node]=arr[st];
    }

    int mid=(st+en)/2;
    return t[node]=f(arr,t,node*2,st,mid)+f(arr,t,node*2+1,mid+1,en);
}
void f1(vll &arr,vll &t,int node,int st,int en,int goal,ll ch){
//printf("s%d %d %d\n",node,st,en);
     if(st==en){
        t[node]+=ch;
        arr[st]+=ch;
        return;
     }
     int mid=(st+en)/2;
     if(goal<=mid){
        t[node]+=ch;
        f1(arr,t,node*2,st,mid,goal,ch);
        return;
     }
     else{
        t[node]+=ch;
        f1(arr,t,node*2+1,mid+1,en,goal,ch);
        return;
     }
}
ll f2(vll &t, int node, int st, int en, int start, int end){
    int mid=(st+en)/2;
    if(en<start)return 0;
    if(end<st)return 0;
    if(start<=st&&en<=end){
        return t[node];
    }
    return f2(t,node*2,st,mid,start,end)+f2(t,node*2+1,mid+1,en,start,end);
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i;
    vll arr(n),t(4*n);
    ll sum=0;
    for(i=0;i<n;i++){
        ll imsi;
        scanf("%lld",&arr[i]);

    }
    sum=f(arr,t,1,0,n-1);

    for(i=0;i<m+k;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1)f1(arr,t,1,0,n-1,b-1,c-arr[b-1]);
        if(a==2)printf("%lld\n",f2(t,1,0,n-1,b-1,c-1));

    }//for(auto &j:arr)printf("a%lld\n",j);
}