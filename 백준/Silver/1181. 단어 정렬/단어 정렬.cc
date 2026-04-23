#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
using namespace std;
vector<pair<int,string>> s;
int main(){
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        string x;
        cin >> x;
        s.push_back(make_pair(x.size(),x));
    }
    sort(s.begin(),s.end());
    cout<<s[0].second<<"\n";
    for(i=1;i<s.size();i++){
        if(!s[i-1].second.compare(s[i].second))continue;
        cout<<s[i].second<<"\n";
    }
}