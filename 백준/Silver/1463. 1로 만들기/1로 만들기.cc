#include<stdio.h>
#include<algorithm>
int ch[1000001];
int f(int n,int cnt){
    if(n==1)return ch[n]=0;
    if(ch[n])return ch[n];
    int a=10000001,b=10000001,c=10000001;
    if(n%3==0){
        a=f(n/3,cnt+1);
    }
    if(n%2==0)b=f(n/2,cnt+1);
    c=f(n-1,cnt+1);
    int as=(std::min(std::min(a,b),c));
    return ch[n]=as+1;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",f(n,0));
}