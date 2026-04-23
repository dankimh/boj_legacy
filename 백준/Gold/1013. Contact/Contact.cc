#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int hoxy=0;
    for(int i=0;i<s.size();){
        if(s[i]=='0'){
            //cout<<i<<"x\n";
            if(i+1==s.size()){
                cout<<"NO\n";
                return;
            }
            if(s[i+1]!='1'){
                cout<<"NO\n";
                return;
            }
            else{
                i+=2;
                continue;
            }
        }
        else if(s[i]=='1'){
            //cout<<i<<"x\n";
            /*if(i+4>s.size()){
                cout<<"3NO\n";
                return;
            }*/
            i++;
            int cnt=0;
            while(s[i]=='0'&&i<s.size()){
                i++;
                cnt++;
            }
            if(cnt<2){
                if(hoxy){
                    if(cnt==1){
                        hoxy=0;
                        i--;
                        continue;
                    }
                }
                cout<<"NO\n";
                return;
            }
            if(i==s.size()){
                cout<<"NO\n";
                return;
            }
            cnt=0;
            while(s[i]=='1'&&i<s.size()){
                i++;
                cnt++;
            }
            if(cnt>1){
                if(i!=s.size()){
                i--;
                hoxy=1;
                }
            }
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}