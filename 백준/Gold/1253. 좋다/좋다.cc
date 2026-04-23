#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i,j;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int cnt=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            auto it=lower_bound(a.begin(),a.end(),a[i]-a[j]);
            auto it2=upper_bound(a.begin(),a.end(),a[i]-a[j]);
            int thr=0;
            if(*it+a[j]==a[i]){
                if(a[j]==0)thr++;
                if(*it==a[j])thr++;
                if(it2-it>thr){cnt++;break;}

            }
        }
    }
    cout<<cnt;
}

