#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,in[10]={0,},rin[10]={0,},mp[10][10],rmp[10][10],ans1[11]={0,},ans2[11]={0,},i;
    cin>>k;
    for(i=0;i<k;i++){
        char c;
        cin>>c;
        if(c=='<'){
            mp[i][i+1]=1;
            in[i+1]++;
            rmp[i+1][i]=1;
            rin[i]++;
        }
        else{
            rmp[i][i+1]=1;
            rin[i+1]++;
            mp[i+1][i]=1;
            in[i]++;
        }
    }
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> ch(10,0);
    for(i=0;i<=k;i++)if(in[i]==0)q.push(i);
    while(!q.empty()){
        int now=q.top();
        q.pop();
        for(i=0;i<10;i++){
            if(ch[i]==0){
                ans1[now]=i;
                ch[i]=1;
                break;
            }

        }
        for(i=0;i<10;i++){
            if(mp[now][i]==1){
                in[i]--;
                if(in[i]==0)q.push(i);
            }
        }
    }
    ch.assign(10,0);
    for(i=0;i<=k;i++)if(rin[i]==0)q.push(i);
    while(!q.empty()){
        int now=q.top();
        q.pop();
        for(i=9;i>=0;i--){
            if(ch[i]==0){
                ans2[now]=i;
                ch[i]=1;
                break;
            }

        }
        for(i=0;i<10;i++){
            if(rmp[now][i]==1){
                rin[i]--;
                if(rin[i]==0)q.push(i);
            }
        }
    }
    for(i=0;i<k+1;i++)cout<<ans2[i];
    cout<<"\n";
    for(i=0;i<k+1;i++)cout<<ans1[i];
}