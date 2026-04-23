#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        int a,b,sum=0;
        scanf("%d %d",&a,&b);
        if(a<1)sum+=0;
        else if(a<2)sum+=500;
        else if(a<4)sum+=300;
        else if(a<7)sum+=200;
        else if(a<11)sum+=50;
        else if(a<16)sum+=30;
        else if(a<22)sum+=10;
        else sum+=0;
        
        if(b<1)sum+=0;
        else if(b<2)sum+=512;
        else if(b<4)sum+=256;
        else if(b<8)sum+=128;
        else if(b<16)sum+=64;
        else if(b<32)sum+=32;
        else sum+=0;

        printf("%d\n",sum*10000);
    }
}