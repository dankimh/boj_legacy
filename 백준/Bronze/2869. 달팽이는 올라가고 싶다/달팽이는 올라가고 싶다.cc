#include<bits/stdc++.h>
int main(){
    int a,b,v;
    scanf("%d %d %d",&a,&b,&v);
    printf("%d",(int)ceil((double)(v-a)/(a-b))+1);
}