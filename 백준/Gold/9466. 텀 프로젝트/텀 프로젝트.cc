#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int i;
    vector<int> choice(n+1);
    for(i=1;i<=n;i++)scanf("%d",&choice[i]);
    vector<int> team(n+1,0);
    int ans=n,turn=1;
    for(i=1;i<=n;i++){
        if(team[i]==1)continue;
        int tu=turn,j=i;
        while(!team[j]){
            team[j]=turn++;
            j=choice[j];
        }
        if(team[j]>=tu){
            ans-=turn-team[j];
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
}