#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,l;
    cin>>n>>l;
    vector<int> a(n);
    int i;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(i=0;i<n;i++){
        cin>>a[i];
        q.push({a[i],i});
        while(q.top().second<i-l+1)q.pop();
        cout<<q.top().first<<" ";
    }


}
