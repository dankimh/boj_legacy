#include<bits/stdc++.h>
using namespace std;
int a[2400][2400];
vector<int> f(int p,int q,int x,int y){
    if(p==x&&q==y){
        vector<int> imsi(3,0);
        imsi[a[p][q]+1]++;
        return imsi;
    }
    int i,j,ch=1;
    for(i=p;i<=x;i++){
        for(j=q;j<=y;j++){
            if(a[p][q]!=a[i][j]){
                ch=0;
                break;
            }
        }
    }
    if(ch){
        vector<int> imsi(3,0);
        imsi[a[p][q]+1]++;
        return imsi;
    }
    vector<int> ans(3,0);
    int seq=(x-p+1)/3;
    for(i=p;i<=x;i+=seq){
        for(j=q;j<=y;j+=seq){
            vector<int> b(3,0);
            b=f(i,j,i+seq-1,j+seq-1);
            for(int k=0;k<3;k++)ans[k]+=b[k];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    vector<int> ans(3);
    ans=f(1,1,n,n);
    printf("%d %d %d",ans[0],ans[1],ans[2]);
}