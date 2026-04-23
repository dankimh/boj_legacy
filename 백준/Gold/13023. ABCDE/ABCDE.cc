#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> a;
int f(int n,int cnt,vector<int> ch){
    if(cnt>3)return cnt;
    int mx=-1;
    for(int i=0;i<a[n].size();i++){
        if(ch[a[n][i]]==0){
            ch[a[n][i]]=1;
            mx=max(mx,f(a[n][i],cnt+1,ch));
            ch[a[n][i]]=0;
        }
    }
    return mx;
}
int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    a.resize(n);
    for(i=0;i<m;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        a[p].push_back(q);
        a[q].push_back(p);
    }
    for(i=0;i<n;i++){
        vector<int> ch(n,0);
        ch[i]=1;
        int ans=f(i,0,ch);
        if(ans>3){
            printf("1");
            return 0;
        }
    }
    printf("0");
}
