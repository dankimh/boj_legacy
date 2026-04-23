#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> ch;
vector<int> now;
bool dfs(int x){
    int i;
    for(i=0;i<mp[x].size();i++){
        int nw=mp[x][i];
        if(ch[nw])continue;
        ch[nw]=true;
        if(now[nw]==-1||dfs(now[nw])){
            now[nw]=x;
            return true;
        }
    }
    return false;
}
bool isprime(int n){
    for (int i=2; i < n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
int main(){
    int n,i,j,k;
    cin>>n;
    vector<int> x(2000);
    mp.resize(n/2);
    ch.resize(n/2);
    now.resize(n/2);
    vector<vector<int>> div(2);
    int first;
    for(i=0;i<n;i++){
        int a;
        cin>>a;
        x[i]=a;
        if(i==0){
            div[0].push_back(a);
        }
        else{
            if(a%2==div[0][0]%2)div[0].push_back(a);
            else div[1].push_back(a);
        }
    }
    if(div[0].size()!=div[1].size()){
        cout<<"-1";
        return 0;
    }
    vector<int> start;
    for(i=0;i<n/2;i++){
        if(isprime(div[0][0]+div[1][i])){
            start.push_back(i);
        }
    }
    int cnt,tot=0;
    vector<int> ans;
    for(k=0;k<start.size();k++){
        fill(now.begin(),now.end(),-1);
        now[start[k]]=0;
        for(i=1;i<n/2;i++){
            for(j=0;j<n/2;j++){
                if(j==start[k])continue;
                if(isprime(div[0][i]+div[1][j])){
                    mp[i].push_back(j);
                }
            }
        }
        cnt=0;
        for(i=1;i<n/2;i++){
            fill(ch.begin(),ch.end(),false);
            ch[start[k]]=true;
            if(dfs(i))cnt++;
        }
        if(cnt==n/2-1){
            tot++;
            for(i=0;i<n/2;i++){
                if(now[i]==0)ans.push_back(div[1][i]);
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(tot==0)cout<<"-1";
    else for(auto &r:ans)cout<<r<<" ";
    
}