#include<bits/stdc++.h>
using namespace std;
//vector<int> vis;
vector<pair<char,char>> mp('Z'+1,{'.','.'});
void f(char node){
    //vis[node]=1;
    cout<<node;
    if(mp[node].first!='.')f(mp[node].first);
    if(mp[node].second!='.')f(mp[node].second);
    return;
}
void m(char node){
    //vis[node]=1;

    if(mp[node].first!='.')m(mp[node].first);
    cout<<node;
    if(mp[node].second!='.')m(mp[node].second);
    return;
}
void r(char node){
    //vis[node]=1;

    if(mp[node].first!='.')r(mp[node].first);
    if(mp[node].second!='.')r(mp[node].second);
    cout<<node;
    return;
}
int main(){
    int n,i;
    cin>>n;
    //vis.resize('z'+1,0);
    for(i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        if(b!='.')mp[a].first=b;
        if(c!='.')mp[a].second=c;
    }
    f('A');
    cout<<"\n";
    m('A');
    cout<<"\n";
    r('A');
}