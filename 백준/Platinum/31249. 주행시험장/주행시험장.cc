#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    if(n==m){
        cout<<n<<" 3\n";
    }
    else if(m<=2*n){
        cout<<n<<" 7\n";
    }
    else if(m==2*n+1){
        if(n==1)cout<<"2 5\n";
        else cout<<n+1<<" 7\n";
    }
    else{
        if(n==1)cout<<"2 "<<2*m-1<<"\n";
        else cout<<n+1<<" "<<2*(m-2*n)+3<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
