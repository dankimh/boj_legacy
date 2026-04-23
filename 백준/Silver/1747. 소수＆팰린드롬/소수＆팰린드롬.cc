#include<stdio.h>
#include<stdlib.h>
int f(int n){
    int i,ans[15],cnt=0;
    while(n>0){
        ans[cnt]=n%10;
        cnt++;
        n/=10;
    }
    int ch=1;
    for(i=0;i<cnt/2;i++){
        if(ans[i]!=ans[cnt-i-1])ch=0;
    }
    return ch;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){printf("2");exit(0);}
    int i,j;
    for(i=n;i<=1003001;i++){
        int ch=0;
        for(j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            if(f(i)){printf("%d",i);exit(0);}
        }
    }
}