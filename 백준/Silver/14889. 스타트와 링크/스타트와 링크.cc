#include<stdio.h>
int abs(int a){
    return a>0?a:-a;
}
int n,a[20][20],min=0xfffffff;
void f(int now,int pers[],int cnt){
    int i,j,who1[n/2],who2[n/2],cnt1=0,cnt2=0;
    if(cnt==n/2-1){
        int ans1=0,ans2=0;
        for(i=0;i<n;i++){
            if(pers[i]==1){
                who1[cnt1++]=i;
            }
            if(pers[i]==0){
                who2[cnt2++]=i;
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                ans1+=a[who1[i]][who1[j]];
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                ans2+=a[who2[i]][who2[j]];
            }
        }
        if(min>abs(ans1-ans2))min=abs(ans1-ans2);
        return;
    }
    for(i=now;i<n;i++){
        if(pers[i]==0){
            pers[i]=1;
            f(i,pers,cnt+1);
            pers[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    int i,j,pers[n]={0,};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    }
    pers[0]=1;
    f(0,pers,0);
    printf("%d",min);
}