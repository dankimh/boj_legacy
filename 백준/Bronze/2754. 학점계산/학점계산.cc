#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    float ans=(float)(-s[0]+'A'+4.0);
    if(s[1]=='+')ans+=0.3;
    else if(s[1]=='-')ans-=0.3;
    if(s=="F")ans=0;
    printf("%.1lf",ans);
}