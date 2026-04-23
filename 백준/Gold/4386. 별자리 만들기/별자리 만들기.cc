#include<bits/stdc++.h>
using namespace std;
vector<int> p;
int f(int u){
    if(u==p[u])return u;
    else return p[u]=f(p[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    p[u]=v;
    return;
}
double dist(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
    int n;
    cin>>n;
    int i,j;
    p.resize(n);
    for(i=0;i<n;i++)p[i]=i;
    vector<pair<double,pair<int,int>>> mp;
    vector<pair<double,double>> dot(n);
    for(i=0;i<n;i++){
        double a,b;
        cin>>dot[i].first>>dot[i].second;
        for(j=0;j<i;j++){
            mp.push_back({dist(dot[i].first,dot[i].second,dot[j].first,dot[j].second),{i,j}});
        }
    }
    sort(mp.begin(),mp.end());
    int cnt=0;
    double cc=0;
    for(i=0;i<mp.size();i++){
        if(cnt==n-1)break;
        int a=mp[i].second.first;
        int b=mp[i].second.second;
        double c=mp[i].first;
        if(f(a)==f(b))continue;
        else{
            uni(a,b);
            cc+=c;
            cnt++;
        }
    }
    cout<<cc;
}
