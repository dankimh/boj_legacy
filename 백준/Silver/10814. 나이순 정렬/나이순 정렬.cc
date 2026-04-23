#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<pair<pair<int,int>,string>> a;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int b;
        string s;
        cin>>b>>s;
        a.push_back(make_pair(make_pair(b,i),s));
    }
    sort(a.begin(),a.end());
    for(auto& x:a){
        cout<<x.first.first<<" "<<x.second<<"\n";
    }
}