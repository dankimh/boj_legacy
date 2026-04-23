#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> maps(200001);
int n;
int main(){
    int i;
    scanf("%d",&n);

    vector<int> rumor(n+1,-1);
    for(i=0;i<n;i++){
        int x;
        while(1){
            scanf("%d",&x);
            if(x==0)break;
            maps[i+1].push_back(x);
        }
    }
    int m;
    scanf("%d",&m);
    vector<int> starter(m);
    vector<int> visit(n+1,-1);
    vector<int> ans(n+1,0);
    queue<pair<int,int>> q;
    for(i=0;i<m;i++)scanf("%d",&starter[i]);
    for(auto &i:starter){
        q.push({i,0});

    }
        while(!q.empty()){
            int now=q.front().first;
            int cnt=q.front().second;
            q.pop();

            if(visit[now]!=-1)continue;
            //printf("x%d %d\n",now,cnt);
            visit[now]=cnt;
            for(int j=0;j<maps[now].size();j++){
                ans[maps[now][j]]++;
            }
            for(int j=0;j<maps[now].size();j++){
                if(visit[maps[now][j]]==-1){
                    if(ans[maps[now][j]]>=(maps[maps[now][j]].size()+1)/2){
                        q.push({maps[now][j],cnt+1});
                    }
                }
            }
        }
    for(i=1;i<=n;i++)printf("%d ",visit[i]);
}