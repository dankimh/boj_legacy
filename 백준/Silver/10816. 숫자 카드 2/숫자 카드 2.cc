#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int main(){
    int n,m,i;

    scanf("%d",&n);
    vector<int> a(n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int b;
        scanf("%d",&b);
        printf("%d\n",upper_bound(a.begin(),a.end(),b)-lower_bound(a.begin(),a.end(),b));
    }
}