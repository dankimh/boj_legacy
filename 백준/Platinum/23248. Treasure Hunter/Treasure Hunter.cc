#include<bits/stdc++.h>
using namespace std;
bool cp(pair<int,int> a,pair<int,int> b){
    if(a.second!=b.second)return a.second<b.second;
    else{
        return a.first<b.first;
    }
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first>b.first&&a.second<b.second)return true;
    else return false;
}
int lb(vector<pair<int,int>> a,int n,pair<int,int> key){
    int st=0,en=n;
    int mid=n;
    while(en-st>0){
        mid=(st+en)/2;
        if(cmp(a[mid],key))st=mid+1;
        else en=mid;
    }
    return en+1;
}
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    int i;
    vector<pair<int,int>> t;
    vector<pair<int,int>> a(k);
    for(i=0;i<k;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),cp);
    /*for(auto &i:a){
        cout<<i.first<<" "<<i.second<<"\n";
    }*/
    t.push_back(a[0]);
    for(i=1;i<k;i++){
        if(cmp(t.back(),a[i])){
            //cout<<a[i].first<<" "<<a[i].second<<"h\n";
            t.push_back(a[i]);
        }
        else{
            int loc=lb(t,t.size(),a[i]);
            t[loc-1]=a[i];
        }
    }
    cout<<t.size();
}