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
vector<int> kmp(string t,string p){
    vector<int> pi=getpi(p);
    vector<int> ans;
    int psiz=(int)p.size(),tsiz=(int)t.size(),i,j=0;
    for(i=0;i<tsiz;i++){
        while(j>0&&t[i]!=p[j]){
            j=pi[j-1];
        }
        if(t[i]==p[j]){
            if(j==psiz-1){
                ans.push_back(i-(psiz-1));
                j=pi[j];
            }
            else j++;
        }
    }
    return ans;
}
int main(){
    string t,p;
    getline(cin,t);
    getline(cin,p);
    auto ans=kmp(t,p);
    printf("%d\n",(int)ans.size());
    for(auto &i:ans)printf("%d ",i+1);
}