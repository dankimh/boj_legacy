#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
#ifdef DEBUG
#define in ifs
#define out ofs
#else
#define in cin
#define out cout
#endif // DEBUG

#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
#define arrin(x,n) for(ll qwer=0;qwer<n;qwer++)cin>>x[qwer];
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF=1e18;
constexpr ll mod=1e9+7;
constexpr ll sz=2020;
ll d[9]= {1,-1,-1,0,1,1,0,-1,1};
void solve(){
    int n,m,i,j;
    int mp[sz][sz]={0,};
    int ob[sz][sz]={0,};
    cin>>n>>m;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){
        cin>>mp[i][j];
    }
    for(i=2;i<n+2;i++){
        mp[i][0]=1;

        mp[i-2][m+1]=1;

    }
    for(i=2;i<m+2;i++){
        mp[0][i]=1;
        mp[n+1][i-2]=1;
    }
    ob[2][0]=1;
    ob[0][2]=2;
    if(n==1||m==1){
        for(i=1;i<=n;i++)for(j=1;j<=m;j++){
            if(mp[i][j]==1){
                cout<<"0";
                return;
            }
        }
        cout<<"1";
        return;
    }
    int ch[sz][sz]={0,};
    queue<pair<int,int>> one,two;
    one.push({2,0});ch[2][0]=1;
    two.push({0,2});ch[0][2]=1;
    while(!one.empty()){
        auto [x,y]=one.front();
        one.pop();
        for(i=0;i<8;i++){
            int nx=x+d[i],ny=y+d[i+1];
            if(nx<0||nx>=n+2||ny<0||ny>=m+2)continue;
            if(ob[nx][ny]==2){
                cout<<"0";
                return;
            }
            if(ch[nx][ny]==0&&mp[nx][ny]==1){
                one.push({nx,ny});
                ch[nx][ny]=1;
                ob[nx][ny]=1;
            }
        }
    }
    while(!two.empty()){
        auto [x,y]=two.front();
        two.pop();
        for(i=0;i<8;i++){
            int nx=x+d[i],ny=y+d[i+1];
            if(nx<0||nx>=n+2||ny<0||ny>=m+2)continue;
            if(ob[nx][ny]==1){
                cout<<"0";
                return;
            }
            if(ch[nx][ny]==0&&mp[nx][ny]==1){
                two.push({nx,ny});
                ch[nx][ny]=1;
                ob[nx][ny]=2;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i==1&&j==1)continue;
            if(i==n&&j==m)continue;
            if(mp[i][j]==0){
                bool a=false,b=false;
                for(int k=0;k<8;k++){
                    int nx=i+d[k],ny=j+d[k+1];
                    if(nx<0||nx>=n+2||ny<0||ny>=m+2)continue;
                    if(ob[nx][ny]==1)a=true;
                    if(ob[nx][ny]==2)b=true;
                }
                if(a&b){
                    cout<<"1";
                    return;
                }
            }
        }
    }
    cout<<"2";
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
