#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<vector<int>> mp,rmp;
vector<int> nums;
stack<pii> s;
vector<int> vis;
int num;
ll CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1;
	else if (temp == 0) return 0;
	else if (temp < 0) return -1;
}

ll cross(vector<pair<ll,ll>> a,vector<pair<ll,ll>> b) {


	pair<ll, ll> A;
	pair<ll, ll> B;
	pair<ll, ll> C;
	pair<ll, ll> D;
	A=a[0];
	B=a[1];
	C=b[0];
	D=b[1];

	ll abc = CCW(A,B,C);
	ll abd = CCW(A,B,D);
	ll cda = CCW(C,D,A);
	ll cdb = CCW(C,D,B);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (A > B)swap(A, B);
		if (C > D)swap(C, D);
		if (A <= D && C <= B)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		return 0;
	}


	if (abc * abd <= 0 && cda * cdb <= 0)
	{
		return 1;
	}
	else
		return 0;
}
int opp(int node){
    return node%2?node+1:node-1;
}
void dfs(int node){
    if(!vis[node]){
        vis[node]=1;
        for(auto &i:mp[node])dfs(i);
        s.push({num,node});
        nums[node]=num;
        num++;
    }
}
void ddfs(int node,vector<vector<int>> &nmp){
    if(!vis[node]){

        vis[node]=1;
        for(auto &i:nmp[node])ddfs(i,nmp);
    }
}
void scc(pii p,vector<int> &ans){
    if(!vis[p.second]){
        vis[p.second]=1;
        ans.push_back(p.second);
        for(auto &i:rmp[p.second])scc({nums[i],i},ans);
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin>>n;
    vector<vector<pll>> lines(n*3+1,vector<pll>(2));
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.resize(6*n+1);
    mp.resize(6*n+1);
    rmp.resize(6*n+1);
    vis.assign(6*n+1,0);

    vector<vector<int>> answer;
    vector<int> cost(6*n+1);
    int i,j;
    for(i=1;i<=n*3;i++){
        cin>>lines[i][0].first>>lines[i][0].second>>lines[i][1].first>>lines[i][1].second;
    }
    for(i=1;i<=n*3;i++){
        for(j=i+1;j<=n*3;j++){
            if(cross(lines[i],lines[j])){
                mp[i*2-1].push_back(j*2);
                mp[j*2-1].push_back(i*2);
                rmp[j*2].push_back(i*2-1);
                rmp[i*2].push_back(j*2-1);
            }
        }
    }
    for(i=1;i<=n*3;i+=3){
        mp[i*2].push_back((i+1)*2-1);
        mp[i*2].push_back((i+2)*2-1);
        mp[(i+1)*2].push_back(i*2-1);
        mp[(i+1)*2].push_back((i+2)*2-1);
        mp[(i+2)*2].push_back(i*2-1);
        mp[(i+2)*2].push_back((i+1)*2-1);
        rmp[i*2-1].push_back((i+1)*2);
        rmp[i*2-1].push_back((i+2)*2);
        rmp[(i+1)*2-1].push_back(i*2);
        rmp[(i+1)*2-1].push_back((i+2)*2);
        rmp[(i+2)*2-1].push_back(i*2);
        rmp[(i+2)*2-1].push_back((i+1)*2);
    }
    for(i=1;i<=6*n;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(6*n+1,0);
    while(!s.empty()){
        vector<int> ans;
        scc(s.top(),ans);
        while(!s.empty()&&vis[s.top().second]==1){
            s.pop();
        }
        answer.push_back(ans);
    }
    int anssiz=(int)answer.size();
    vector<int> node(6*n+1);
    for(int i=0; i<anssiz;i++){
        for(int j=0;j<answer[i].size();j++){
            node[answer[i][j]]=i;
        }
    }
    vector<int> ret;
    for(i=1;i<=3*n;i++){
        if(node[i*2]==node[i*2-1]){
            cout<<"-1";
            exit(0);
        }
        else if(node[i*2]>node[i*2-1]){
            ret.push_back(i);
        }
    }
    cout<<ret.size()<<"\n";
    for(auto &i:ret){
        cout<<i<<' ';
    }
}
