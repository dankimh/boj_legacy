#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    n=n%8;
    if(n==0)n=2;
    if(n==7)n=3;
    if(n==6)n=4;
    printf("%d",n);
}