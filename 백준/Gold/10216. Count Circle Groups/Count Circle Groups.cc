#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,x[3000],y[3000],r[3000],v[3000]={0,0,},cnt=0;
        queue<int> q;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d %d",&x[i],&y[i],&r[i]);
        }
        for(i=0;i<n;i++){
            if(v[i]==0){
                q.push(i);
                while(!q.empty()){
                    int now=q.front();
                    //printf("now%d - %d\n",i,now);
                    v[now]=1;
                    q.pop();
                    for(int j=0;j<n;j++){
                        //printf("l%d-%d-%d\n",((x[now]-x[j])*(x[now]-x[j])+(y[now]-y[j])*(y[now]-y[j])),(r[now]+r[j])*(r[now]+r[j]));
                        if(v[j]==0&&((x[now]-x[j])*(x[now]-x[j])+(y[now]-y[j])*(y[now]-y[j]))<=(r[now]+r[j])*(r[now]+r[j])){
                            q.push(j);
                            //printf("j%d\n",j);
                        }
                    }
                }
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}