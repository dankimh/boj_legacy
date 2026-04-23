#include<stdio.h>
int main(){
    int prime[100001],cnt=0;
    int n,i,s;
    scanf("%d %d",&n,&s);
    for(i=0;i<n;i++){
        scanf("%d",&prime[i]);
    }
    prime[n]=0;
    int front=0,rear=0,sum=0,ans=100001;
    while(rear<=n){
        //printf("a%d %d %d\n",front,rear,sum);
        if(sum<s){
            sum+=prime[rear++];
        }
        else if(sum==s){
            if(ans>rear-front)ans=rear-front;
            sum+=prime[rear++];
        }
        else {
            if(ans>rear-front)ans=rear-front;
            sum-=prime[front++];
        }
    }
    int min=100001;
    if(ans>100000)printf("0");
    else printf("%d",ans);
}