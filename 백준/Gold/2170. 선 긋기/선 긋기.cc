#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    vector<pair<int,int>> dot;
    for(i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dot.push_back({a,b});
    }
    sort(dot.begin(),dot.end());
    int fr=dot[0].first,re=dot[0].second,ans=0;
    for(i=1;i<n;i++){
        if(re>=dot[i].first){
            re=max(re,dot[i].second);
        }
        else{
            ans+=re-fr;
            fr=dot[i].first;
            re=dot[i].second;
        }
    }
    printf("%d",ans+(re-fr));
}