#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    vector<vector<int>> moim(m);
    for(i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        for(j=0;j<k;j++){
            int ai;
            scanf("%d",&ai);
            moim[i].push_back(ai-1);
        }
    }
    vector<int> gamyom(n);
    vector<int> init(n);
    int tot=0;
    for(i=0;i<n;i++){
        scanf("%d",&gamyom[i]);
        if(gamyom[i]==1)tot++;
    }
    vector<int> chance(m,1);
    copy(gamyom.begin(),gamyom.end(),init.begin());
    for(i=m-1;i>=0;i--){
        int k=moim[i].size();
        int ch=0;
        for(j=0;j<k;j++){
            if(init[moim[i][j]]==0){
                chance[i]=0;
                ch=1;
                break;
            }
        }
        if(ch){
            for(j=0;j<k;j++){
                init[moim[i][j]]=0;
            }
        }
    }
    vector<int> f(n);
    copy(init.begin(),init.end(),f.begin());
    for(i=0;i<m;i++){
        int k=moim[i].size();
        int ch=0;
        for(j=0;j<k;j++){
            if(f[moim[i][j]]==1){
                chance[i]=0;
                ch=1;
                break;
            }
        }
        if(ch){
            for(j=0;j<k;j++){
                f[moim[i][j]]=1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(f[i]!=gamyom[i]){
            printf("%s","NO");
            return 0;
        }
    }
    printf("%s\n","YES");
    for(i=0;i<n;i++){
        printf("%d ",init[i]);
    }
}