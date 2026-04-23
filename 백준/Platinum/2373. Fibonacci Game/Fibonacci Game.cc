#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fibo;
void fib(){
    fibo.push_back(1);
    fibo.push_back(1);
    for(int i=2;i<81;i++){
        fibo.push_back(fibo[i-2]+fibo[i-1]);
    }
}
int main(){
    ll n;
    cin>>n;
    fib();
    if(find(fibo.begin(),fibo.end(),n)!=fibo.end()){
        cout<<"-1";
        return 0;
    }
    while(n>0){
        auto it=upper_bound(fibo.begin(),fibo.end(),n);
        //cout<<*(it-1)<<"c\n";
        if(*(it-1)==n){
            cout<<n;
            return 0;
        }
        n-=*(it-1);
    }
}