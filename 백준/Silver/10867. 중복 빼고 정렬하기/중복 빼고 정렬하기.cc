#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n,i,a[100001];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        //printf("%d ",a[i]);
        if(a[i]==a[i+1])continue;
        else printf("%d ",a[i]);
    }
    printf("%d",a[n-1]);
}
