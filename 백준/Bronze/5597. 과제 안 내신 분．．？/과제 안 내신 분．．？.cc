#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> ch(31,0);
    int i;
    for(i=0;i<28;i++){
        int x;
        cin>>x;
        ch[x]=1;
    }
    for(i=1;i<31;i++){
        if(ch[i]==0)cout<<i<<"\n";
    }
}