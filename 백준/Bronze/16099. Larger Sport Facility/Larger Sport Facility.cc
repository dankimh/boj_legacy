#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*b>c*d)cout<<"TelecomParisTech\n";
    if(a*b==c*d)cout<<"Tie\n";
    if(a*b<c*d)cout<<"Eurecom\n";
    }
    
}