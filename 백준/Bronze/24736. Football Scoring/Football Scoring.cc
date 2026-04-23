#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]={6,3,2,1,2};
    for(int i=0;i<2;i++){
        int x=0;
        for(int j=0;j<5;j++){
            int b;
            cin>>b;
            x+=b*a[j];
        }
        cout<<x<<" ";
    }
}