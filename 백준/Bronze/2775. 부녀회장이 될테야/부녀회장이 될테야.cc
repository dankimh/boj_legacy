#include<stdio.h>
int main(){
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int k,n;
        int a[14],b[14];
        for(int j=0;j<14;j++){
            a[j]=j+1;
            b[j]=0;
        }
        scanf("%d %d",&k,&n);
        for(int j=0;j<k;j++){
            for(int l=0;l<n;l++){
                b[l]=0;
            }
            for(int l=0;l<n;l++){
                //b[l]=0;
                for(int r=0;r<=l;r++){
                    b[l]+=a[r];
                }

            }
            for(int l=0;l<n;l++){
                a[l]=b[l];
            }
        }
        printf("%d\n",b[n-1]);
    }
}