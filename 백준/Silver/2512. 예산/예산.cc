#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,a[10000],i,h;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    scanf("%d",&h);
    int st=0,en=h,mi;
    while(st<=en){
        long long sum=0;
        mi=(st+en)/2;
        //printf("%d %d %d\n",st,en,mi);
        for(i=0;i<n;i++){
            if(a[i]<=mi)sum+=a[i];
            else sum+=mi;
        }
        if(sum<=h)st=mi+1;
        else en=mi-1;
    }
    if(mi>a[n-1])printf("%d",a[n-1]);
    else printf("%d",en);
}