#include<bits/stdc++.h>
using namespace std;
vector<int> a;
void f(int st,int en){
    if(st>en)return;
    if(st==en){cout<<a[st]<<"\n";return;}
    int i;
    for(i=st+1;i<=en;i++){
        if(a[i]>a[st])break;
    }
    f(st+1,i-1);
    f(i,en);
    cout<<a[st]<<"\n";
    return;
}
int main(){
    int n;
    while(cin>>n){
        a.push_back(n);
    }
    f(0,a.size()-1);
}