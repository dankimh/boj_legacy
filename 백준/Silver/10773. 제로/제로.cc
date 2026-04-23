#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,i,a;
    scanf("%d",&k);
    stack<int> s;
    for(i=0;i<k;i++){
        scanf("%d",&a);
        if(a==0)s.pop();
        else s.push(a);
    }
    int b=0;
    while(!s.empty()){
        b+=s.top();
        s.pop();
    }
    printf("%d",b);
}