#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,i;
    cin>>n>>m;
    vector<int> book(n);
    for(i=0;i<n;i++)cin>>book[i];
    sort(book.begin(),book.end());
    auto idx=lower_bound(book.begin(),book.end(),0)-book.begin();
    vector<int> pos,neg;
    ll ans=0;
    for(i=n-1;i>=idx;i-=m){
        ans+=2*(book[i]);
    }

    for(i=0;i<idx;i+=m){
        ans+=2*(-book[i]);
    }

    ans-=max(abs(book[0]),abs(book[n-1]));
    cout<<ans;
}

