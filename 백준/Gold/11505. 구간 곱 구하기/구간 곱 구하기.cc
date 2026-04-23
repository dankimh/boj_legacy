#include<stdio.h>
#include<vector>
#include<math.h>
#define ll long long
#define vll vector<ll>
#define mod 1000000007
using namespace std;
ll p(ll a,ll b){
    ll ex=mod-2,ans=1;
    while(ex){
        if(ex%2){
            ans*=a;
            ans%=mod;
        }
        ex/=2;
        a*=a;
        a%=mod;
    }
    return (ans*b)%mod;
}
ll f(vll &arr,vll &t,int node,int st,int en){

    if(st==en){
        return t[node]=arr[st];
    }

    int mid=(st+en)/2;
    return t[node]=(f(arr,t,node*2,st,mid)*f(arr,t,node*2+1,mid+1,en))%mod;
}
void f1(vll &arr,vll &t,int node,int st,int en,int goal,ll nw){
//printf("s%d %d %d\n",node,st,en);
     //if(goal<st||goal>en)return t[node];
     //if(st==en)return t[node]=arr[goal]=nw;
    if(goal<st||goal>en)return;
     if(st==en){
        int mold=arr[goal];
        if(mold==0)mold=1;
        int mt=t[node];
        if(mt==0)mt=1;
        t[node]=mt*p(mold,nw)%mod;
     }

     if(st!=en){
        int mid=(st+en)/2;
        f1(arr,t,node*2,st,mid,goal,nw);
        f1(arr,t,node*2+1,mid+1,en,goal,nw);
     t[node]=(t[node*2]*t[node*2+1])%mod;

     }
     //
     //return t[node]=(f1(arr,t,node*2,st,mid,goal,nw)*f1(arr,t,node*2+1,mid+1,en,goal,nw))%mod;
}
ll f2(vll &t, int node, int st, int en, int start, int end){
    int mid=(st+en)/2;
    if(en<start)return 1;
    if(end<st)return 1;
    if(start<=st&&en<=end){
        return t[node];
    }
    return (f2(t,node*2,st,mid,start,end)*f2(t,node*2+1,mid+1,en,start,end))%mod;
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i;
    vll arr(n),t(4*n,0);
    ll sum=0;
    for(i=0;i<n;i++){
        ll imsi;
        scanf("%lld",&arr[i]);
    }
    sum=f(arr,t,1,0,n-1);
    for(i=0;i<m+k;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a==1){
            f1(arr,t,1,0,n-1,b-1,c);
            arr[b-1]=c;
        }
        if(a==2)printf("%lld\n",(f2(t,1,0,n-1,b-1,c-1)+mod)%mod);
    }//for(auto &j:arr)printf("a%lld\n",j);
}