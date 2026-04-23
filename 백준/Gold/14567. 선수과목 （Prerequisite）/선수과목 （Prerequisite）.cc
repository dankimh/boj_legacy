#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp1(n);
    vector<vector<int>> mp2(n);
    vector<int> ans(n,0);
    int i;
    vector<pair<int,int>> pre(m);
    for(i=0;i<m;i++){
        cin>>pre[i].first>>pre[i].second;
        mp1[pre[i].first-1].push_back(pre[i].second-1);
        mp2[pre[i].second-1].push_back(pre[i].first-1);
    }
    queue<pair<int,int>> q;
    vector<int> ch(n,0);
    for(i=0;i<n;i++){
        if(mp2[i].size()==0){q.push({i,1});}
    }

    while(!q.empty()){
        auto now=q.front();
        //cout<<now.first+1<<"\n";
        q.pop();
        if(ch[now.first]){
            continue;
        }
        ch[now.first]=1;
        ans[now.first]=now.second;
        for(i=0;i<mp1[now.first].size();i++){
            int x=mp1[now.first][i];
            //cout<<mp1[now.first][i]+1<<"x\n";
            if(ch[x]==0){
                int chk=1;
                for(int j=0;j<mp2[x].size();j++){
                    if(ch[mp2[x][j]]==0){
                        chk=0;
                        break;
                    }
                }
                if(chk){
                    //cout<<mp1[now.first][i]+1<<"y\n";
                    q.push({mp1[now.first][i],now.second+1});
                }
            }
        }
    }
    for(auto& x:ans)cout<<x<<" ";
}