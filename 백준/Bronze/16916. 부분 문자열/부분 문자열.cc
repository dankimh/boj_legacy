#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(string p){
    int psiz=(int)p.size();
    int i,j=0;
    vector<int> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
int main(){
    string p,s;
    cin>>p;
    cin>>s;
    vector<int> pi=getpi(p);
    int i,j=0;
    for(i=0;i<p.size();i++){

        while(j>0&&p[i]!=s[j])j=pi[j-1];
        if(p[i]==s[j]){
            if(j==s.size()-1){
                printf("1");
                return 0;
            }
            else j++;
        }
    }
    printf("0");
}