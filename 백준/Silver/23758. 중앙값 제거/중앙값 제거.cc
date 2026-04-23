#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int cnt=0;
    while(n>0){
        n/=2;
        cnt++;
    }
    return cnt-1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,i;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    for(i=0;i<(n+1)/2;i++)ans+=f(a[i]);
    cout<<ans+1;
}
