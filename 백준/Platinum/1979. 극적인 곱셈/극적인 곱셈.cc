#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> num;
    num.push_back(k);
    int remain=0,now=k;
    for(int i=0;i<1000;i++){
        int x=(now*n+remain);
        //cout<<x<<"x\n";
        if(x==k)break;
        num.push_back(x%10);
        remain=x/10;
        now=x%10;
    }
    if(num.back()==0)cout<<"0";
    else for(int i=num.size()-1;i>=0;i--)cout<<num[i];
}