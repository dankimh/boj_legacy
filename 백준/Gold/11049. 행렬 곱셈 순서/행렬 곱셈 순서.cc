#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int>> a(500);
int mem[500][500];
ll f(int fr,int re){
    if(mem[fr][re])return mem[fr][re];
    int asiz=re-fr+1;
    if(asiz==1)return mem[fr][re]=0;
    int i;
    ll ans=0xffffffffff;
    for(i=0;i<asiz-1;i++){
        ans=min(ans,f(fr,fr+i)+f(fr+i+1,re)+a[fr].first*a[fr+i].second*a[re].second);
    }
    return mem[fr][re]=ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    printf("%lld",f(0,n-1));
}