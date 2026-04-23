#include<stdio.h>
#include<algorithm>
int ch[1000001];
int b[1000001];
int f(int n){
    ch[1]=0;
    b[1]=-1;
    for(int i=2;i<=n;i++){
        ch[i]=ch[i-1]+1;
        b[i]=i-1;
        if(i%2==0&&ch[i]>ch[i/2]+1){
            ch[i]=ch[i/2]+1;
            b[i]=i/2;
        }
        if(i%3==0&&ch[i]>ch[i/3]+1){
            ch[i]=ch[i/3]+1;
            b[i]=i/3;
        }
    }
    return ch[n];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    while(n!=-1){
        printf("%d ",n);
        n=b[n];
    }
}