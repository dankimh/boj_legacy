#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> parent,rnk;
ll fi(ll u){
    if(parent[u]==u)return u;
    return parent[u]=fi(parent[u]);
}
void uni(ll u,ll v){
    u=fi(u);
    v=fi(v);
    if(u==v)return;
    if(rnk[u]>rnk[v]){
        parent[v]=u;
        rnk[u]+=rnk[v];
    }
    else{
        parent[u]=v;
        rnk[v]+=rnk[u];
    }
    return;
}
ll CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1; // 반시계
	else if (temp == 0) return 0; // 일직선
	else if (temp < 0) return -1; // 시계
}

ll check(vector<pair<ll,ll>> a,vector<pair<ll,ll>> b) {


	pair<ll, ll> A;
	pair<ll, ll> B;
	pair<ll, ll> C;
	pair<ll, ll> D;
	A=a[0];
	B=a[1];
	C=b[0];
	D=b[1];

	//ABC
	ll abc = CCW(A,B,C);
	//ABD
	ll abd = CCW(A,B,D);
	//CDA
	ll cda = CCW(C,D,A);
	//CDB
	ll cdb = CCW(C,D,B);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (A > B)swap(A, B);
		if (C > D)swap(C, D);
		//first 비교가 아닌 것은 x가 같고 y가 달라서 일직선일 수 있으므로..
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
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    ll n;
    cin>>n;
    ll i,j;
    parent.resize(n);
    rnk.resize(n);
    for(i=0;i<n;i++){parent[i]=i;rnk[i]=1;}
    vector<vector<pair<ll,ll>>> dot(n,vector<pair<ll,ll>> (2));
    for(i=0;i<n;i++){
        //scanf("%lld %lld %lld %lld",&dot[i][0].first,&dot[i][0].second,&dot[i][1].first,&dot[i][1].second);
        cin>>dot[i][0].first>>dot[i][0].second>>dot[i][1].first>>dot[i][1].second;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(check(dot[i],dot[j])==1){
                //if(fi(dot[i])))
                //cout<<i<<' '<<j<<"\n";
                uni(i,j);
            }
        }
    }

    vector<ll> p(n,0);
    for(i=0;i<n;i++)ll imsi=fi(i);
    for(i=0;i<n;i++){
        //cout<<parent[i]<<"\n";
        p[fi(i)]++;
    }
    ll mx=-1,cnt=0;
    for(i=0;i<n;i++){
        if(parent[i]==i)cnt++;
        if(mx<p[i])mx=p[i];
    }
    cout<<cnt<<"\n"<<mx;
}