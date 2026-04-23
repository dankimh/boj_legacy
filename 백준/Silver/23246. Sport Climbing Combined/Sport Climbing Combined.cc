#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
    int i,aa=1,bb=1;
    for(i=1;i<4;i++){
        aa*=a[i];
        bb*=b[i];
    }
    //cout<<aa<<" "<<bb<<"a\n";
    if(aa!=bb)return aa<bb;
    aa=0;bb=0;
    for(i=1;i<4;i++){
        aa+=a[i];
        bb+=b[i];
    }
    //cout<<aa<<" "<<bb<<"b\n";
    if(aa!=bb)return aa<bb;
    else return a[0]<b[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(4));
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<4;j++)cin>>a[i][j];
    sort(a.begin(),a.end(),cmp);
    for(i=0;i<3;i++){
        cout<<a[i][0]<<" ";
    }
}