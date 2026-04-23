#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,x;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    x=0;
    sort(a.begin(),a.end());
    int st=0,en=n-1,ans=2000000001,p=0,q=n-1;
    while(st<en){
        int sum=a[st]+a[en];
        //printf("%d %d %d %d\n",st,en,sum,ans);
        if(ans>abs(sum)){ans=abs(sum);p=st;q=en;}
        if(sum<x)st++;
        else if(sum>x)en--;
        else{
            st++;
        }
    }
    printf("%d %d",a[p],a[q]);
}
