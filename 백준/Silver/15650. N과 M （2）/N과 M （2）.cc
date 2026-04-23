#include<stdio.h>
int n,m;
int a[20]={0,},b[20]={0,};
void f(int t,int c){
    //printf("tc%d %d\n",t,c);
    b[t]=c;
    a[c]=1;
    if(t==m-1){
        for(int i=0;i<m;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        b[t]=0;
        a[c]=0;
        return;
    }

    for(int i=c;i<=n;i++){
        if(a[i]==0){f(t+1,i);}
    }
    b[t]=0;
    a[c]=0;
    return;
}
int main(){

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        f(0,i);
    }
}