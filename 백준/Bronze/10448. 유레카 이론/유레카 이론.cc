#include<stdio.h>
int b[100];
bool f(int a,int k){
    if(k==0){
        if(a==0)return true;
        else return false;
    }
    int i=0;
    while(b[i]<=a){
        if(f(a-b[i],k-1))return true;
        i++;
    }
    return false;
}
int main(){
    int n,a,i;
    b[0]=1;
    for(i=1;i<100;i++){
        b[i]=i+b[i-1]+1;
        //printf("%d ",b[i]);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        printf("%d\n",f(a,3));
    }
}