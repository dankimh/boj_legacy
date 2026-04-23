#include<stdio.h>
int f(int n){
    if(n==1||n==0)return 1;
    return n*f(n-1);
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d",f(a));
}