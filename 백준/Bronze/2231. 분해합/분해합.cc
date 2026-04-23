#include<stdio.h>
int f(int n){
    int c=0;
    while(n>0){
        c+=(n%10);
        n/=10;
    }
    return c;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        if(n==f(i)+i)break;
    }
    if(i==n)printf("0");
    else printf("%d",i);
}