#include<bits/stdc++.h>
using namespace std;
vector<int> f{0,1,2,-1,-1,5,9,-1,8,6};
bool cmp(string a,string b){
    return a+b>b+a;
}
string flip(string a){
    for(auto &i:a){
        if(f[i-'0']!=-1){
            i='0'+f[i-'0'];
        }
    }
    reverse(a.begin(),a.end());
    //cout<<a<<"a\n";
    return a;
}
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    int i;
    string m;
    for(i=0;i<n;i++){
        cin>>a[i];
        auto x=(flip(a[i]));
        if(m.size()<x.size())m=flip(x);
        else if(m.size()==x.size()){
            if(flip(m)<x)m=flip(x);
        }
    }
    //cout<<m<<"m\n";
    a.push_back(((m)));
    for(auto &x:a){x=flip(x);}
    //for(auto &x:a)cout<<x;
    //cout<<"aa\n";
    sort(a.begin(),a.end(),cmp);
    string ans;
    for(auto &x:a){
        ans+=x;
    }
    cout<<flip(ans);
}