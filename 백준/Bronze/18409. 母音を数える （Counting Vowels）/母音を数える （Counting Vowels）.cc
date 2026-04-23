#include<bits/stdc++.h>
using namespace std;
int main(){
    char x[5]={'a','e','i','o','u'};
    int n;
    cin>>n;
    string s;
    cin>>s;
    int z=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(s[i]==x[j]){
                z++;
                break;
            }
        }
    }
    cout<<z;
}