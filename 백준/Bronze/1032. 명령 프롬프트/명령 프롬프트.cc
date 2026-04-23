#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<a[0].size();i++){
        int ch=1;
        char check=a[0][i];
        for(int j=1;j<n;j++){
            if(a[j][i]!=check)ch=0;
        }
        if(ch)cout<<check;
        else cout<<"?";
    }
}