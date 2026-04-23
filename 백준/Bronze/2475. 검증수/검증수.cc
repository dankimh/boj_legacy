#include<stdio.h>
int main(){
    int a,i,s=0;
    for(i=0;i<5;i++){
        scanf("%d",&a);
        s+=a*a;
    }
    printf("%d",s%10);
}