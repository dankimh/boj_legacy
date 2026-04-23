#include<bits/stdc++.h>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("input.txt");ofs.open("output.txt");
#ifdef DEBUG
    #define in ifs
    #define out ofs
#else
    #define in cin
    #define out cout
#endif // DEBUG
using namespace std;
typedef long long ll;
void solve(){
    ll n,i,j,now=0,mx=-1;
    cin>>n;
    vector<string> mp(2);
    for(i=0;i<2;i++){
        cin>>mp[i];
        for(j=0;j<n;j++){
            if(mp[i][j]=='#')break;
        }
        if(mx<j){
            mx=j;
            now=i;
        }
    }
    //cout<<now<<"n\n";
    ll ans=0;
    for(i=0;i<n;i++){
        //cout<<ans<<" "<<now<<"x\n";
        if(mp[now][i]=='#'){
            ans--;
            now^=1;
        }
        else{
            if(mp[now^1][i]!='#')ans++;
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
}
