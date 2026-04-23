#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    int i=1;
    while(b--){
        i*=a;
        i%=10;
    }
    cout<<(i>0?i:10)<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}