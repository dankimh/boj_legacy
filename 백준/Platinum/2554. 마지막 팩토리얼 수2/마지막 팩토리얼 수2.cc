#include<bits/stdc++.h>
using namespace std;
vector<int> d={1,1,2,6,4,2,2,4,2,8};
string div5(string s){
    string ret;
    if(s[0]>='5'){
        s[0]-=5;
        ret+='1';
    }
    for(int i=1;i<s.size();i++){
        //cout<<ret<<"r\n";
        int x=(s[i-1]-'0')*10+(s[i]-'0');
        //cout<<x<<"x\n";
        ret+=(x/5+'0');
        x=x-(x%5);
        s[i-1]-=(x/10)%10;
        s[i]-=x%10;
        //cout<<s<<"s\n";
    }
    return ret;
}
int f(string x){
    //cout<<x<<"x\n";
    string xx={x.back()};
    if(x.size()<2)return d[x[0]-'0'];
    else{
        if((x[x.size()-2]-'0')%2){
            return (4*f(div5(x))*f(xx))%10;
        }
        else return (6*f(div5(x))*f(xx))%10;
    }
}
int main(){
    string s;
    cin>>s;
    cout<<f(s);
}