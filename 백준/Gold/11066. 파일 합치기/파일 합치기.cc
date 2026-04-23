#include<bits/stdc++.h>
using namespace std;
int mem[501][501];
vector<int> a(500);
int cmp(int a,int b){
    return a<b?a:b;
}
int f(int fr,int re){
    if(mem[fr][re])return mem[fr][re];
    int asiz=re-fr+1;

    int i,sum=0;
    for(i=fr;i<=re;i++)sum+=a[i];
    if(asiz==1)return mem[fr][re]=0;
    if(asiz==2)return mem[fr][re]=a[fr]+a[re];
    if(asiz==3){
        int p=a[fr],q=a[fr+1],r=a[fr+2];
        int res=cmp(p+q+q+p+r,q+r+q+r+p);
        return mem[fr][re]=res;
    }
    int ans=0xfffffff;
    for(i=0;i<asiz-1;i++){
        ans=cmp(ans,f(fr,fr+i)+f(fr+i+1,re));
    }
    return mem[fr][re]=ans+sum;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k,i,j;
        scanf("%d",&k);
        int sum=0;
        for(i=0;i<501;i++)for(j=0;j<501;j++)mem[i][j]=0;
        for(i=0;i<k;i++){scanf("%d",&a[i]);sum+=a[i];}
        int ans=f(0,k-1);
        printf("%d\n",ans);
    }
}