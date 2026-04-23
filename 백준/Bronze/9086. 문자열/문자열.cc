#include<bits/stdc++.h>
int main(){
    int t,i;
    char a[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",a);
        printf("%c%c\n",a[0],a[strlen(a)-1]);
    }
}