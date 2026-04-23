#include<stdio.h>
int main(){
    int n,a[10001]={0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<10001;i++){
        for(int j=0;j<a[i];j++){
            printf("%d\n",i);
        }
    }
}