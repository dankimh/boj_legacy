#include<bits/stdc++.h>
#define ch(x,y,j) if(x+d[j]<0||x+d[j]>=r||y+d[j+1]<0||y+d[j+1]>=c)continue;
using namespace std;
int mx=-1,d[5]={0,1,0,-1,0},r,c;
char mp[21][21];
void f(int x,int y,int cnt,vector<int> chk){
    //if(chk[mp[x][y]-'A']==1)return;
    chk[mp[x][y]-'A']=1;
    int i;
    for(i=0;i<4;i++){
        ch(x,y,i);
        if(chk[mp[x+d[i]][y+d[i+1]]-'A']==1)continue;
        f(x+d[i],y+d[i+1],cnt+1,chk);
    }
    if(cnt>mx)mx=cnt;
    return;
}
int main(){
    scanf("%d %d",&r,&c);
    int i,j;
    for(i=0;i<r;i++)scanf("%s",mp[i]);
    vector<int> chk(26,0);
    f(0,0,1,chk);
    printf("%d",mx);
}