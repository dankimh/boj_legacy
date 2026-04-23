#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum<(i+1)*(i)/2){
            cout<<"-1";
            return 0;
        }
    }
    if(sum==(n)*(n-1)/2)cout<<"1";
    else cout<<"-1";
    //else cout<<"-1";
}