#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s=to_string(n);
    int ch=0;
    for(auto &i:s){
        if(i=='7')ch=1;
    }
    if(ch==0){
        if(n%7==0)cout<<"1";
        else cout<<"0";
    }
    else{
        if(n%7==0)cout<<"3";
        else cout<<"2";
    }
}