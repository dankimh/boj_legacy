#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    int y=(c*d-a*f)/(b*d-a*e);
    int x;
    if(a==0){
        x=(f-e*y)/d;
    }
    else x=(c-b*y)/a;
    printf("%d %d",x,y);
}