#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i,a=0,b=0,c=0,d=0,ans=0;
    for(i=0;i<n/2;i++){
        if(s[i]=='2'){
            if(s[n-1-i]=='2')ans++;
            else if(s[n-i-1]=='3')a++;
            else if(s[n-i-1]=='E')b++;
        }
        else if(s[i]=='3'){
            if(s[n-1-i]=='E')ans++;
            else if(s[n-i-1]=='3')c++;
            else if(s[n-i-1]=='2')a++;
        }
        else{
            if(s[n-1-i]=='3')ans++;
            else if(s[n-i-1]=='2')b++;
            else if(s[n-i-1]=='E')d++;
        }
    }
    for(i=0;i<=k;i++){
        cout<<ans*2<<"\n";
        if(c!=0&&d!=0){
            c--;
            d--;
            ans+=2;
            continue;
        }
        if(a!=0&&b!=0){
            a--;
            b--;
            ans+=2;
            continue;
        }
        if((a!=0&&d!=0)){
            a--;
            d--;
            b++;
            ans++;
            continue;
        }
        if(b!=0&&c!=0){
            b--;
            c--;
            a++;
            ans++;
            continue;
        }
        if(a>1){
            a-=2;
            c++;
            ans++;
            continue;
        }
        if(b>1){
            b-=2;
            d++;
            ans++;
            continue;
        }
    }
}