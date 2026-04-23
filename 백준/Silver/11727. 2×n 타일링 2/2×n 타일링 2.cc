#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1001]={0,1,3},n,i;
    scanf("%d",&n);
    for(i=3;i<=n;i++)a[i]=(2*a[i-2]+a[i-1])%10007;
    printf("%d",a[n]);
}