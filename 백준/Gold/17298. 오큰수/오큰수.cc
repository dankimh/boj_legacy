#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,a;
    scanf("%d",&n);
    stack<pair<int,int>> s;
    vector<int> ans(n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
            while(!s.empty()&&s.top().first<a){
                ans[s.top().second]=a;
                s.pop();
            }

        s.push({a,i});

    }
    while(!s.empty()){
        ans[s.top().second]=-1;
        s.pop();
    }
    for(auto &i:ans)printf("%d ",i);
}