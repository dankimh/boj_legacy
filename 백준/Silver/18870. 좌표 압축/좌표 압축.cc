#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
vector<pair<int,int>> a;
vector<pair<int,int>> c;
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int b;
        scanf("%d",&b);
        a.push_back(make_pair(b,i));
    }
    sort(a.begin(),a.end());
    int j=0;
    c.push_back(make_pair(a[0].second,j));
    j++;
    for(i=1;i<n;i++){
        if(a[i].first==a[i-1].first){
            c.push_back(make_pair(a[i].second,c[i-1].second));
        }
        else{
            c.push_back(make_pair(a[i].second,j));
            j++;
        }
    }
    sort(c.begin(),c.end());
    for(auto& k:c){
        printf("%d ",k.second);
    }
}