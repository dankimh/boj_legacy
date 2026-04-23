#include<bits/stdc++.h>
int main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        int h,w,n;
        scanf("%d %d %d",&h,&w,&n);
        printf("%d\n",((n-1)%h+1)*100+((n-1)/h+1));
    }
}
