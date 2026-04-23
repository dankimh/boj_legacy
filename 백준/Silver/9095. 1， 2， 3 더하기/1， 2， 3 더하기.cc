#include<bits/stdc++.h>
int f(int a){
    if(a==0)return 0;
    if(a==1)return 0;
    if(a==2)return 1;
    return f(a-1)+f(a-2)+f(a-3);
}
int main(){
    int n,a,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        printf("%d\n",f(a+2));
    }
}
