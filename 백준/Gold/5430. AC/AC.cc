#include<bits/stdc++.h>
using namespace std;
void solve(){
    string func;
    cin>>func;
    int n,i;
    cin>>n;
    string s;
    cin>>s;
    deque<int> a;
    string t;
    int status=1;
    for(auto &i:s){
        if(i>='0'&&i<='9')t+=i;
        else if(i==','){a.push_back(stoi(t));t.clear();}
        else continue;
    }
    if(!t.empty())a.push_back(stoi(t));
    for(i=1;i<func.size();i++){
        if(func[i-1]=='R'&&func[i]=='R'){
            func[i-1]=func[i]='X';
        }
    }
    for(i=0;i<func.size();i++){
        if(func[i]=='R')status*=-1;
        else if(func[i]=='D'){
            if(a.size()==0){
                cout<<"error\n";
                return;
            }
            if(status==1){
                a.pop_front();
            }
            else a.pop_back();
        }
    }
    cout<<"[";
    if(status==1){

        for(i=0;i<a.size();i++){
            cout<<a[i];
            if(i<a.size()-1)cout<<",";
        }
    }
    if(status==-1){

        for(i=a.size()-1;i>=0;i--){
            cout<<a[i];
            if(i>0)cout<<",";
        }
    }
    cout<<"]\n";
    return;
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tt;
    cin>>tt;
    while(tt--)solve();
}