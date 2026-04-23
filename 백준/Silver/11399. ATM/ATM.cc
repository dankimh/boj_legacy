#include<stdio.h>
#include<algorithm>
int main(){
    int n;
    scanf("%d",&n);
    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    int m=0;
    for(int i=0;i<n;i++){
        m+=(n-i)*a[i];
    }
    printf("%d",m);
}