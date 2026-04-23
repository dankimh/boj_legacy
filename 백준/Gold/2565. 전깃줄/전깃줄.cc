
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    vector<pair<int,int>> a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        a.push_back({p,q});
    }
    sort(a.begin(),a.end());
    vector<int> ans;
    ans.push_back(1);
    for(i=1;i<a.size();i++){
        int max=0;
        for(j=0;j<i;j++){
            if(a[j].second<a[i].second&&max<ans[j])max=ans[j];
        }
        ans.push_back(max+1);
    }
    int max=0;
    for(auto &i:ans)if(max<i)max=i;
    printf("%d",n-max);
}