#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<vector<int>> mp,rmp;
vector<int> nums;
stack<int> s;
vector<int> vis;
int num=0;
ll CCW(pll p1,pll p2,pll p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1;
	else if (temp == 0) return 0;
	else if (temp < 0) return -1;
}

ll cross(vector<pll> a,vector<pll> b) {


	pll A,B,C,D;
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
int f(int a){
    return a=a<0?-(a*2)-1:a*2;
}
void add(int a,int b){
    mp[a].push_back(b);
    rmp[b].push_back(a);
}
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
int main(){

    int w,p,i,j;
    cin>>w>>p;
    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.assign(p*2+1,0);
    mp.resize(p*2+1);
    rmp.resize(p*2+1);
    vis.assign(p*2+1,0);
    vector<pll> water(w+1);
    for(i=1;i<=w;i++){
        cin>>water[i].first>>water[i].second;
    }
    vector<vector<pll>> pipe(p+1);
    for(i=1;i<=p;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pipe[i].push_back(water[a]);
        pipe[i].push_back({b,c});
    }
    for(i=1;i<=p;i++){
        for(j=i+1;j<=p;j++){
            if(cross(pipe[i],pipe[j])){
                if(pipe[i][0]==pipe[j][0])continue;
                else{
                    int x,y;
                    x=f(i);y=f(j);
                    add(opp(x),y);
                    add(opp(y),x);
                    add(y,opp(x));
                    add(x,opp(y));
                }
            }
        }
    }
    vector<vector<int>> answer;
    for(i=1;i<=2*p;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(p*2+1,0);
    while(!s.empty()){
        int x=s.top();s.pop();
        if(!nums[x]){
            num++;
            scc(x);
        }
    }
    for(i=1;i<=p;i++){
        if(nums[i*2]==nums[i*2-1]){
            printf("impossible\n");
            exit(0);
        }
    }

    printf("possible\n");
}