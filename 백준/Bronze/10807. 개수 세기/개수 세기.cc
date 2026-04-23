#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    int v;
    cin>>v;
    int x=0;
    for(auto& z:a){
        if(v==z)x++;
    }
    cout<<x;
}