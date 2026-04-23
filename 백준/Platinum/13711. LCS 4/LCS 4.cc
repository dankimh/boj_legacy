#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first<b.first;
}
int main(){
    vector<pair<int,int>> a,b;
    vector<int> aloc;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int p;
        scanf("%d",&p);
        a.push_back({p,i});
    }
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)aloc.push_back(a[i].first);
    for(i=0;i<n;i++){
        int p;
        scanf("%d",&p);
        int loc=lower_bound(aloc.begin(),aloc.end(),p)-aloc.begin();
        b.push_back({a[loc].second,p});
    }
    int ch[100001],cnt=0;
    vector<pair<int,int>> lcs;
    lcs.push_back(b[0]);
    for(i=1;i<n;i++){
        if(b[i].first>lcs.back().first)lcs.push_back(b[i]);
        else{
            int loc=lower_bound(lcs.begin(),lcs.end(),b[i],comp)-lcs.begin();
            lcs[loc]=b[i];
        }
    }
    printf("%d",lcs.size());
}