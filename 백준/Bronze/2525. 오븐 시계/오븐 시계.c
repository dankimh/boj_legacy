#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    b+=c;
    if(b>59){
        a+=(b/60);
        b%=60;
    }
    if(a>23){
        a%=24;
    }
    printf("%d %d",a,b);
}
