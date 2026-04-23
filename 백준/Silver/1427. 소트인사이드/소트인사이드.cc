#include<stdio.h>
#include<algorithm>
int main(){
    int n;
    scanf("%d",&n);
    int a[10],i=0;
    while(n>0){
        a[i]=n%10;
        i++;
        n/=10;
    }
    std::sort(a,a+i);
    for(int j=i-1;j>=0;j--)printf("%d",a[j]);
}