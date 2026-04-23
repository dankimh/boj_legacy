#include<utility>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
    int n,i,now=0,cnt=0;
    scanf("%d",&n);
    vector<pair<int, int>> a(n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].second,&a[i].first);
    }
    sort(a.begin(),a.end());
    for(auto& i:a){
         if(i.second<now)continue;
         else{
            now=i.first;
            cnt++;
         }
    }
    printf("%d",cnt);
}