#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<utility>
using namespace std;
int prime[20000],cnt=0;
int g(int a,int b){
    int time=0,i;
    //printf("g%d %d \n",a,b);
    for(i=0;i<4;i++){
        if(a%10!=b%10)time++;
        a/=10;
        b/=10;
    }
    //printf("%d\n",time);
    if(time==1)return 1;
    else return 0;
}
int main(){
    int i;
    for(i=1000;i<=10000;i++){
        int ch=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            prime[cnt]=i;
            cnt++;
        }
    }
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int n,m,j;
        scanf("%d %d",&n,&m);
        queue<pair<int,int>> q;
        int visit[10000]={0,},ans=-1,now;
        q.push({n,0});
        while(!q.empty()){
            //    _sleep(100);
            now=q.front().first;
            int k;
            ans=q.front().second;
            q.pop();
            //printf("a%d %d\n",now,ans);
            visit[now]=1;
            if(now==m)break;
            for(k=0;k<cnt;k++){
                if(g(now,prime[k])&&visit[prime[k]]==0){
                    q.push({prime[k],ans+1});
                }
            }
        }
        if(now!=m)printf("Impossible");
        else printf("%d\n",ans);
    }
}