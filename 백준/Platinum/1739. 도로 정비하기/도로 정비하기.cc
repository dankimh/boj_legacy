#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<vector<int>> mp,rmp;
vector<int> nums;
stack<int> s;
vector<int> vis;
int num=0;
int opp(int node){
    return node%2?node+1:node-1;
}
void dfs(int node){
    vis[node]=1;
    for(auto &i:mp[node]){if(!vis[i])dfs(i);}
    s.push(node);
}
void scc(int node){
    nums[node]=num;
    for(auto &i:rmp[node])if(!nums[i])scc(i);
    return;
}
int f(int a){
    return a=a<0?-(a*2)-1:a*2;
}
void add(int a,int b){
    mp[a].push_back(b);
    rmp[b].push_back(a);
}
void MAIN(){

    int n,m,i,j,k;
    cin>>n>>m>>k;
    int sz=n+m;
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.assign(sz*2+1,0);
    mp.resize(sz*2+1);
    rmp.resize(sz*2+1);
    vis.assign(sz*2+1,0);
    for(i=0;i<k;i++){
        int a,b,c,d,ch=0;
        int p,q,r,s;
        cin>>a>>b>>c>>d;
        if(a==c&&b==d)continue;
        b+=n;d+=n;
        a=f(a);b=f(b);c=f(c);d=f(d);
        if(a<c){p=b;q=d;}
        else {p=opp(b);q=opp(d);}
        if(b<d){r=a;s=c;}
        else {r=opp(a);s=opp(c);}
        if(a==c){
            add(opp(r),s);
            add(opp(s),r);
        }
        else if(b==d){
            add(opp(p),q);
            add(opp(q),p);
        }
        else{
            add(opp(p),q);
            add(opp(q),p);
            add(opp(p),r);
            add(opp(r),p);
            add(opp(s),q);
            add(opp(q),s);
            add(opp(s),r);
            add(opp(r),s);
        }
    }

    vector<vector<int>> answer;
    for(i=1;i<=2*sz;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(sz*2+1,0);
    while(!s.empty()){
        int x=s.top();s.pop();
        if(!nums[x]){
            num++;
            scc(x);
        }
    }
    for(i=1;i<=sz;i++){
        if(nums[i*2]==nums[i*2-1]){
            printf("No\n");
            return;
        }
    }

    printf("Yes\n");
}
int main(){
    int tt;
    cin>>tt;
    while(tt--)MAIN();
}