#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int x=a*3+b*20+c*120;
    int y=d*3+e*20+f*120;
    if(x>y)cout<<"Max";
    else if(x==y)cout<<"Draw";
    else cout<<"Mel";
}