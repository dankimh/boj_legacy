#include<bits/stdc++.h>
using namespace std;
int mx;
bool cmp(string a,string b){
    return a+b>b+a;
}
int main(){
    int n,k;
    cin>>k>>n;
    vector<string> a(k);
    int i,m=-1;
    for(i=0;i<k;i++){
        int x;
        cin>>x;
        a[i]=to_string(x);
        if(m<x)m=x;
    }
    for(i=k;i<n;i++)a.push_back(to_string(m));
    sort(a.begin(),a.end(),cmp);
    for(auto &x:a){
        cout<<x;
    }
}