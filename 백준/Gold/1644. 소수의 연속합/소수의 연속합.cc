#include<stdio.h>
int main(){
    int prime[2000000],cnt=0;
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        int ch=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            prime[cnt]=i;
            cnt++;
        }
    }
    //for(i=0;i<cnt;i++)printf("%d ",prime[i]);
    int front=0,rear=0,sum=0,ans=0;
    while(rear<=cnt){
        //printf("a%d\n",sum);
        if(sum<n){
            sum+=prime[rear++];
        }
        else if(sum==n){
            ans++;
            sum+=prime[rear++];
        }
        else {
            sum-=prime[front++];
        }
    }
    printf("%d",ans);
}