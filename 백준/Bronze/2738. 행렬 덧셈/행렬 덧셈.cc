#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[200][200],b[200][200],i,j;
    int n,m;
    cin>>n>>m;
    for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>a[i][j];
    for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>b[i][j];
    for(i=0;i<n;i++){for(j=0;j<m;j++)cout<<a[i][j]+b[i][j]<<" ";cout<<"\n";}
}