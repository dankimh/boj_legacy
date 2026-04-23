#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> ch;//visited
vector<int> match;//matched node(right->left)
vector<vector<char>> classroom;
pair<int,int> dd[6]={{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,1}};
bool dfs(int x){
    for(int i=0;i<mp[x].size();i++){
        int now=mp[x][i];
        if(ch[now])continue;
        ch[now]=true;
        if(match[now]==-1||dfs(match[now])){
            match[now]=x;
            return true;
        }
    }
    return false;
}
bool check(int x,int y,int a,int b,pair<int,int> d){
    if(x+d.first<0||x+d.first>=a||y+d.second<0||y+d.second>=b){
        return false;
    }
    if(classroom[x+d.first][y+d.second]=='x')return false;
    return true;
}
int seq(int x,int y,int a){
    return x*a+y;
}
void solve(){
    int a,b;
    cin>>a>>b;
    classroom.clear();
    mp.clear();
    ch.clear();
    match.clear();
    classroom.resize(a);
    mp.resize(a*b);
    ch.resize(a*b,false);
    match.resize(a*b,-1);
    
    fill(match.begin(),match.end(),-1);
    int i,j,seat=0;
    for(i=0;i<a;i++){
        
        for(j=0;j<b;j++){
            char x;
            cin>>x;
            if(x=='.')seat++;
            classroom[i].push_back(x);
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if(classroom[i][j]=='x')continue;
            if(j%2)continue;
            for(int k=0;k<6;k++){
                if(check(i,j,a,b,dd[k])){
                    //cout<<i<<" "<<j<<" "<<i+dd[k].first<<" "<<j+dd[k].second<<"\n";
                    mp[seq(i,j,b)].push_back(seq(i+dd[k].first,j+dd[k].second,b));
                }
            }
        }
    }
    int cnt=0;
    for(i=0;i<a*b;i++){
        fill(ch.begin(),ch.end(),false);
        if(dfs(i))cnt++;
    }
    /*for(i=0;i<n;i++){
        cout<<(match[i])%n+1<<" "<<i+1<<"n\n";
    }*/
    cout<<seat-cnt<<"\n";;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}