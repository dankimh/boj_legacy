#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if((n+1)%(n%100)==0)cout<<"Good\n";
    else cout<<"Bye\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}