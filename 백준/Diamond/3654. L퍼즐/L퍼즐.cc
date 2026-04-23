#include<bits/stdc++.h>
#define input cin
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<vector<int>> mp,rmp;
vector<int> nums;
vector<int> s;
vector<int> vis;
vector<vector<int>> answer;
int num=0,d[5]={0,-1,0,1,0};
int loc(int i,int j,int n,int m){
    return (i-1)*m+j;
}
int sccloc(int i,int j,int k,int n,int m){
    int x=loc(i,j,n,m);
    if(k==0)return x-1;
    else if(k==1)return x+n*m-m;
    else if(k==2)return x;
    else if(k==3)return x+n*m;
}
int opp(int node){
    return node%2?node+1:node-1;
}
void dfs(int node){
    if(!vis[node]){
    vis[node]=1;
    for(auto &i:mp[node]){if(!vis[i])dfs(i);}
    s.push_back(node);
    }
}
void scc(int node){
    if(!nums[node]){
    nums[node]=num;
    for(auto &i:rmp[node])if(!nums[i])scc(i);
    return;
    }
}
int f(int a){
    return a=a<0?-(a*2)-1:a*2;
}
void add(int a,int b){
    mp[a].push_back(b);
    rmp[b].push_back(a);
}
void orr(int a,int b){
    a=f(a);
    b=f(b);
    add(opp(a),b);
    add(opp(b),a);
    return;
}
char mmp[555][555];
void MAIN(){

    int n,m,i,j,k,l,bl=0,wh=0;
    input>>n>>m;
    int sz=2*n*m;
    s.clear();
    answer.clear();
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();
    nums.resize(sz*2+1,0);
    mp.resize(sz*2+1);
    rmp.resize(sz*2+1);
    vis.resize(sz*2+1,0);

    memset(mmp,'.',sizeof(mmp));
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)input>>mmp[i][j];
    for(i=1;i<=n;i++){

        for(j=1;j<=m;j++){
            if(mmp[i][j]=='B'){
                bl++;
                for(k=0;k<2;k++){
                    bool a=mmp[i+d[k]][j+d[k+1]]=='W';
                    bool b=mmp[i+d[k+2]][j+d[k+3]]=='W';
                    int loc1=sccloc(i,j,k,n,m);
                    int loc2=sccloc(i,j,k+2,n,m);
                    if(a&&b){
                        orr(loc1,loc2);
                        orr(-loc1,-loc2);
                    }
                    else if(a){
                        orr(loc1,loc1);
                    }
                    else if(b){
                        orr(loc2,loc2);
                    }
                    else {
                        printf("NO\n");
                        return;
                    }
                }
                for(int k=0;k<4;k++)for(l=0;l<k;l++){
                    if(mmp[i+d[k]][j+d[k+1]]=='B'&&mmp[i+d[l]][j+d[l+1]]=='B'){
                        int loc1=sccloc(i,j,k,n,m);
                        int loc2=sccloc(i,j,l,n,m);
                        orr(loc1,-loc1);
                        orr(loc2,-loc2);
                    }
                }
            }
            else if(mmp[i][j]=='W'){
                wh++;
                for(int k=0;k<4;k++)for(l=0;l<k;l++){
                    int loc1=sccloc(i,j,k,n,m);
                    int loc2=sccloc(i,j,l,n,m);
                    if(mmp[i+d[k]][j+d[k+1]]=='B'&&mmp[i+d[l]][j+d[l+1]]=='B'){
                        orr(-loc1,-loc2);
                    }
                }
            }
        }
    }
    num=0;

    for(i=1;i<=2*sz;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(sz*2+1,0);
    while(!s.empty()){
        int x=s.back();s.pop_back();
        if(!nums[x]){
            num++;
            scc(x);

        }
    }
    for(i=1;i<=sz;i++){
        if(nums[i*2]==nums[i*2-1]){
            printf("NO\n");
            return;
        }
    }
    if(bl*2!=wh)printf("NO\n");
    else printf("YES\n");
}
int main(){
    int tt;
    input>>tt;
    while(tt--)MAIN();
}