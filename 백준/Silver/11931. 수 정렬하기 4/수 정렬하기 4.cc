#include<stdio.h>
#include<algorithm>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
    int n,a[1000000],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n,f);
    for(i=0;i<n;i++)printf("%d\n",a[i]);
}
