#include<stdio.h>
int mp[16],cnt,n;
void f(int t){
    if(t==n){cnt++;return;}
    int i;
    for(i=0;i< n;i++){
        int c=0;
        for(int j=0;j<t;j++){
            if(mp[j]==i||j+mp[j]==t+i||j-mp[j]==t-i){c=1;break;}
        }
        if(!c){
            mp[t]=i;
            f(t+1);
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    f(0);
    printf("%d",cnt);
}
