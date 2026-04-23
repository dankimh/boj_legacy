#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#include<numbers>
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
constexpr ll sz=201;
constexpr double pi=acos(-1);
ll d[9]= {1,-1,-1,0,1,1,0,-1,1};

using cd=complex<double>;

double maximize(vector<vector<int>>& c, int n){
    vector<double> a(n,0);
    vector<double> b(n,0);
    vector<int> grad_a(n,0);
    int iter=0,i,j;
    double tol=-1,eta=0.01;
    double lossbef=-numeric_limits<double>::infinity();
    //printf("1\n");
    while(iter<10000){
        vector<int> grad_a(n,0);
        double loss=0;
        for(i=0;i<n;i++){
            double minval=INF;
            int thatj=0;
            for(j=0;j<n;j++){
                if(minval>b[j]+c[i][j]){
                    minval=b[j]+c[i][j];
                    thatj=j;
                }
            }
            grad_a[thatj]++;
            loss+=(minval-b[i]);
        }
        //cout<<loss<<"x\n";
//printf("2\n");
        //if tolerance
        if(abs(lossbef-loss)<tol){
            lossbef=loss;
            break;
        }
//printf("3\n");
        lossbef=loss;

        for(j=0;j<n;j++){
            double grad=(double)(grad_a[j]-1);
            //cout<<grad<<" "<<eta<<"\n";
            b[j]+=eta*grad;
        }
        //print(b);
        //cout<<lossbef<<" "<<iter<<"\n";
        iter++;
        //printf("4\n");
    }
    return lossbef;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> c(n,vector<int>(n));
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)cin>>c[i][j];
    cout<<round(maximize(c,n));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
