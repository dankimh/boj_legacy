#include<stdio.h>
int main(){
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        long long x,y,a=2,c=0;
        scanf("%d %d",&x,&y);
        long long sub=y-x;
        while(c<sub){
            c+=a/2;
            a++;
        }
        printf("%d\n",a-2);
    }
}