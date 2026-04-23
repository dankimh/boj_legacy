#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        int v,e;
        scanf("%d %d",&v,&e);
        vector<vector<int>> map(v+1);
        int i;
        for(i=0;i<e;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            map[a].push_back(b);
            map[b].push_back(a);
        }
        vector<int> visit(v+1,0);

        int ch=1;
        for(i=1;i<=v;i++){
            if(visit[i]==0){
                visit[i]=1;
                int j;
                queue<pair<int,int>> q;
                vector<int> red,blue;
                q.push({i,0});
                while(!q.empty()){
                    int now=q.front().first;
                    int color=q.front().second;
                    q.pop();
                    //printf("x%d %d\n",now,color);
                    if(color)red.push_back(now);
                    else blue.push_back(now);
                    visit[now]=1;
                    for(auto &j:map[now]){
                        if(visit[j]==0){
                            //printf("in%d %d\n",now,j);
                            //visit[j]=1;
                            q.push({j,!color});
                        }
                    }
                }
                vector<pair<int,int>> total;
                for(auto &j:red){
                    total.push_back({j,0});
                }
                for(auto &j:blue){
                    total.push_back({j,1});
                }
                sort(total.begin(),total.end());
                for(j=1;j<total.size();j++){
                    if(total[j-1].first==total[j].first){
                        if(total[j-1].second!=total[j].second){
                            ch=0;
                            break;
                        }
                    }
                }
                if(!ch)break;
            }
        }
        if(ch)printf("YES\n");
        else printf("NO\n");
    }
}