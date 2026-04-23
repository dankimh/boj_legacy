#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,i,j;
    cin>>m;
    vector<int> a(m+1);
    for(i=1;i<=m;i++)cin>>a[i];
    vector<vector<int>> b(m+1);
    i=1;
    int cnt=0;
    for(j=1;j<=m;j++)b[j].push_back(a[j]);
    while(i<500001){
        for(j=1;j<=m;j++){
            int imsi=b[j].back();
            //cout<<i<<"-"<<j<<"-"<<imsi<<"\n";
            b[j].push_back(b[imsi][cnt]);
        }
        cnt++;
        i*=2;
    }
    /*for(j=1;j<=m;j++){
        for(auto &k:b[j])cout<<k<<" ";
        cout<<"\n";
    }*/
    int q;
    cin>>q;
    for(i=0;i<q;i++){
        int n,x;
        cin>>n>>x;
        int ans=x,base=0;
        while(n>0){
            if(n%2){
                ans=b[ans][base];
            }
            //cout<<"x-"<<ans<<"\n";
            base++;
            n/=2;
        }
        cout<<ans<<"\n";
    }
}
