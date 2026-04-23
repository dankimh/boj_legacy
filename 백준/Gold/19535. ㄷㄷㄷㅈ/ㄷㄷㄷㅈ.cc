#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
int t[300001][2];
int main(){
    int n;

    scanf("%d",&n);
    mp.resize(n+1);
    int i;
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        t[i][0]=a;
        t[i][1]=b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int d=0,g=0;
    for(i=0;i<n-1;i++){
        d+=(mp[t[i][0]].size()-1)*(mp[t[i][1]].size()-1);
    }
    for(i=1;i<=n;i++){
        int nowsize=mp[i].size();
        if(nowsize>2){
            g+=(nowsize*(nowsize-1)*(nowsize-2))/6;
        }
    }
    //printf("%d %d\n",d,g);
    if(d>g*3)printf("D");
    else if(d<g*3)printf("G");
    else printf("DUDUDUNGA");
}