#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a<b)cout<<"Bus";
    if(a==b)cout<<"Anything";
    if(a>b)cout<<"Subway";
}