#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int arr[100];
    int i;
    for(i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int ex=n-1;
        int a=1,b=0,c=0,d=1;
        int da=6,db=-4,dc=1,dd=0;
        while(ex){
            if(ex%2){
                int ta=a,tb=b,tc=c,td=d;
                a=(ta*da+tb*dc)%1000;
                b=(ta*db+tb*dd)%1000;
                c=(tc*da+td*dc)%1000;
                d=(tc*db+td*dd)%1000;
            }
            int aaa=da,bbb=db,ccc=dc,ddd=dd;
            da=(aaa*aaa+bbb*ccc)%1000;
            db=(aaa*bbb+bbb*ddd)%1000;
            dc=(ccc*aaa+ddd*ccc)%1000;
            dd=(ccc*bbb+ddd*ddd)%1000;
            ex/=2;
        }
        int ans=c*28+d*6;
        arr[i]=(ans+10999)%1000;

    }
    for(i=0;i<t;i++){
        printf("Case #%d: %03d\n",i+1,(arr[i]+1000)%1000);
    }
}