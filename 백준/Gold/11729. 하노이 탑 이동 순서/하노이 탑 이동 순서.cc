#include<stdio.h>
#include<math.h>
void h(int n,int a,int b,int c){
    if(n==1)printf("%d %d\n",a,c);
    else{
        h(n-1,a,c,b);
        printf("%d %d\n",a,c);
        h(n-1,b,a,c);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(int)pow(2,n)-1);
    h(n,1,2,3);
}
