#include<bits/stdc++.h>
#define INF 0xfffffff
#define macro(a,b,c) if(a+dir[c]<0||a+dir[c]>=h||b+dir[c+1]<0||b+dir[c+1]>=w)continue;
using namespace std;
vector<vector<int>> maps(500,vector<int>(500));
vector<vector<int>> units(300000,vector<int>(4));
vector<int> danger(10);
struct cmp{
    bool operator()(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return a.second>b.second;
}
};

int dir[5]={0,1,0,-1,0};
int main(){
    int n,h,w;
    scanf("%d %d %d",&n,&h,&w);
    int i,j;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++)scanf("%d",&maps[i][j]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&danger[i]);
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++)maps[i][j]=danger[maps[i][j]];
    }
    vector<vector<int>> unitmaps(500,vector<int>(500));
    vector<vector<int>> unitloc(500,vector<int>(500,0));
    unitmaps=maps;
    int m;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        for(j=0;j<4;j++)scanf("%d",&units[i][j]);
        if(units[i][1]==0)units[i][1]=-1;
        unitloc[units[i][2]][units[i][3]]=units[i][1];
    }
    int k;
    scanf("%d",&k);
    vector<vector<int>> djik(500,vector<int>(500));
    while(k--){
        int u,a,b;
        scanf("%d %d %d",&u,&a,&b);

        int nowx=units[u][2];
        int nowy=units[u][3];
        int nowstamina=units[u][0];
        int nowwho=units[u][1];
        if(maps[a][b]<0)continue;
        if(unitloc[a][b])continue;

        for(i=-21;i<=21;i++){
            for(j=-21;j<=21;j++){
                if(nowx+i<0||nowx+i>=h||nowy+j<0||nowy+j>=w)continue;
                djik[nowx+i][nowy+j]=INF;
            }
        }
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp> q;
        q.push({{nowx,nowy},0});
        djik[nowx][nowy]=0;
        int chd=0;
        while(!q.empty()){
            int x=q.top().first.first;
            int y=q.top().first.second;
            int dis=q.top().second;
            q.pop();
            if(djik[x][y]<dis)continue;


            for(j=0;j<4;j++){
                macro(x,y,j);
                if(unitmaps[x+dir[j]][y+dir[j+1]]==-1)continue;
                if(unitloc[x+dir[j]][y+dir[j+1]]==-(nowwho))continue;
                if(x+dir[j]==a&&y+dir[j+1]==b){
                    djik[a][b]=dis+unitmaps[x+dir[j]][y+dir[j+1]];
                    chd=1;
                    break;
                }
                if(chd)break;
                int chw=1;

                for(int l=0;l<4;l++){
                    macro(x+dir[j],y+dir[j+1],l);
                    if(x==x+dir[j]+dir[l]&&y==y+dir[j+1]+dir[l+1])continue;
                    if(unitloc[x+dir[j]+dir[l]][y+dir[j+1]+dir[l+1]]==-nowwho){
                        chw=0;
                        break;
                    }
                }
                if(!chw)continue;
                if(dis+unitmaps[x+dir[j]][y+dir[j+1]]>nowstamina)continue;

                if(djik[x+dir[j]][y+dir[j+1]]>dis+unitmaps[x+dir[j]][y+dir[j+1]]){
                    q.push({{x+dir[j],y+dir[j+1]},dis+unitmaps[x+dir[j]][y+dir[j+1]]});
                    djik[x+dir[j]][y+dir[j+1]]=dis+unitmaps[x+dir[j]][y+dir[j+1]];
                }

            }
            if(chd)break;
        }
        if(chd){
            if(djik[a][b]<=nowstamina){
                unitloc[nowx][nowy]=0;
                unitloc[a][b]=nowwho;
                units[u][2]=a;
                units[u][3]=b;
            }
        }
    }
    for(i=1;i<=m;i++){
        printf("%d %d\n",units[i][2],units[i][3]);
    }
    return 0;
}