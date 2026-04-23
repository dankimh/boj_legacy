#include<bits/stdc++.h>
using namespace std;
long long f(long long x){
    if(x==0)return 1;
    return x*f(x-1);
}
int main(){
    long long x;
    cin>>x;
    cout<<f(x);
}