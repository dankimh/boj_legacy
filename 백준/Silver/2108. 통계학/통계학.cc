#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int i,s=0;
    vector<int> x(9000,0);
    for(i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        x[a[i]+4000]++;
    }
    sort(a.begin(),a.end());
    cout<<(int)round((double)s/(double)n)<<"\n";;

    cout<<a[n/2]<<"\n";

    vector<int> p;
    auto mx=max_element(x.begin(),x.end());
    int t=0,z=0;
    for(i=0;i<9000;i++){
        if(x[i]==*mx){
            z=i-4000;
            if(t==1){
                cout<<i-4000<<"\n";
                t++;
                break;
            }
            t++;
        }
    }
    if(t==1)cout<<z<<"\n";
    cout<<*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
}
