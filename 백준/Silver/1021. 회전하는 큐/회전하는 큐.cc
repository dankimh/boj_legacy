#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,ans=0;
    cin>>n>>m;
    vector<int> a(m);
    for(i=0;i<m;i++)cin>>a[i];
    deque<int> q;
    for(i=1;i<=n;i++)q.push_back(i);
    for(i=0;i<m;i++){
        int cnt=0;
        while(1){
            int now=q[0];
            q.pop_front();
            if(now==a[i])break;
            q.push_back(now);
            cnt++;
        }
        if(cnt>(q.size()+1)/2){
            cnt=(q.size()+1)-cnt;
        }
        ans+=cnt;
    }
    cout<<ans;
}