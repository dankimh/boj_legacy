#include<bits/stdc++.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    a=(a/100)+((a/10)%10)*10+(a%10)*100;
    b=(b/100)+((b/10)%10)*10+(b%10)*100;
    printf("%d",a>b?a:b);
}
