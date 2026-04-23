
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[303][303];
    int i,j,x,y,cnt=0;
    for(i=0;i<m;i++)for(j=0;j<n;j++)cin>>a[i][j];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            int mp[11][11]={0,};
            for(x=1;x<=10;x++){
                if(i+x-1>=m)break;
                for(y=1;y<=10;y++){
                    if(x*y>10)continue;
                    if(j+y-1>=n)break;
                    mp[x][y]=mp[x-1][y]+mp[x][y-1]-mp[x-1][y-1]+a[i+x-1][j+y-1];
                    if(mp[x][y]==10)cnt++;
                }
            }
        }
    }
    cout<<cnt;
}