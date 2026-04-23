#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(string p){
    int siz=(int)p.size(),i,j=0;
    vector<int> pi(siz,0);
    for(i=1;i<siz;i++){
        while(j>0&&p[i]!=p[j]){
            j=pi[j-1];
        }
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
int main(){
    while(1){
        string s;
        getline(cin,s);
        if(s==".")break;
        auto pi=getpi(s);
        int siz=(int)s.size();
        int endkmp=pi[siz-1];
        if(siz%2==0){
            if(endkmp<siz/2)printf("1\n");
            else printf("%d\n",siz/(siz-endkmp));
        }
        else{
            if(siz%(siz-endkmp)!=0)printf("1\n");
            else printf("%d\n",siz/(siz-endkmp));
        }
    }
}