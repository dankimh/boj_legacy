#include<stdio.h>
int main(){
    int n,i,sum=0,a,m=-1001,ch=-1001;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        sum+=a;
        if(m<sum)m=sum;
        if(sum<0)sum=0;
        if(a<=0&&ch<a)ch=a;
    }
    if(m<sum)m=sum;
    if(m==0)m=ch;
    printf("%d",m);
}
