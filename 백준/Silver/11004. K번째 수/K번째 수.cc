#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5000000],i,n,k;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d",a[k-1]);
}