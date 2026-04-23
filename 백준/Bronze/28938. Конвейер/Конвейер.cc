#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        c+=a;
    }
    if(c>0)cout<<"Right";
    else if(c==0)cout<<"Stay";
    else cout<<"Left";
}