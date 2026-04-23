
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int g[2500][2500],ch[2500];
int CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1; // 반시계
	else if (temp == 0) return 0; // 일직선
	else if (temp < 0) return -1; // 시계
}

bool check(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {

	
	pair<int, int> A={x1,y1};
	pair<int, int> B={x2,y2};
	pair<int, int> C={x3,y3};
	pair<int, int> D={x4,y4};
	
	//ABC
	int abc = CCW(A,B,C);
	//ABD
	int abd = CCW(A,B,D);
	//CDA
	int cda = CCW(C,D,A);
	//CDB
	int cdb = CCW(C,D,B);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (A > B)swap(A, B);
		if (C > D)swap(C, D);
		//first 비교가 아닌 것은 x가 같고 y가 달라서 일직선일 수 있으므로..
		if (A <= D && C <= B)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

	if (abc * abd <= 0 && cda * cdb <= 0)
	{
		return true;
	}
	else
		return false;
}
bool cmp(pair<int,int> v1,pair<int,int> v2){
  if(v1.first == v2.first)
    return v1.second<v2.second;
  else return v1.first>v2.first;
}
int main(){
    ll n,i,j;
    
    cin>>n;
    vector<pair<ll,ll>> b(n);
    vector<ll> a[2500];
    for(i=0;i<n;i++){
        ll x;
        for(j=0;j<4;j++){
            cin>>x;
            a[i].push_back(x);
        }
        b[i].second=i;
        cin>>x;
        b[i].first=x;
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            
            bool x=check(a[i][0],a[i][1],a[i][2],a[i][3],a[j][0],a[j][1],a[j][2],a[j][3]);
            if(check(a[i][0],a[i][1],a[i][2],a[i][3],a[j][0],a[j][1],a[j][2],a[j][3])){
                g[i][j]=1;
                g[j][i]=1;
            }
            //cout<<x<<"\n";
        }
    }
    
    ll ans=0;
    sort(b.begin(),b.end(),cmp);
    for(i=0;i<n;i++){
        ll cnt=0;
        ch[b[i].second]=1;
        for(j=0;j<i;j++){
            if(i==j)continue;
            if(ch[b[j].second]==1){
                if(g[b[i].second][b[j].second]==1){
                    cnt++;
                }
            }
            
        }
        //cout<<cnt<<"x\n";
        ans+=(cnt+1)*b[i].first;
    }
    cout<<ans;
}