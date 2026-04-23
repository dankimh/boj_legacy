#include<bits/stdc++.h>
using namespace std;
int main(){
    int ch=1;
    for(int i=0;i<8;i++){
        int x;
        cin>>x;
        if(x==9)ch=0;
    }
    if(ch)cout<<"S";
    else cout<<"F";
}