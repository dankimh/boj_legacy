#include<bits/stdc++.h>
using namespace std;
void solve(){

}
int main(){
    int tt=0,cnt=0;
    //cin>>tt;
    //while(tt--)solve();

    for(int i=0;i<64;i++){
        if(i%8==0){
            if((i/8)%2==0)tt=1;
            else if((i/8)%2)tt=0;
        }
        char a;
        cin>>a;
        if(tt&&a=='F')cnt++;
        tt=(!tt);
    }
    cout<<cnt++;
}