#include<bits/stdc++.h>
using namespace std;
string a[7]={"Never gonna give you up","Never gonna let you down","Never gonna run around and desert you","Never gonna make you cry","Never gonna say goodbye","Never gonna tell a lie and hurt you","Never gonna stop"};
int main(){
    int n,xx=1;
    cin>>n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        int ch=0;
        for(int i=0;i<7;i++){
            if(s==a[i]){ch++;}
        }
        if(ch==0&&xx==1){
            cout<<"Yes";
            xx=0;
        }
    }
    if(xx)cout<<"No";
}