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
    string a;
    cin>>a;
    int max=-1;
    int asiz=(int)a.size();
    for(int i=0;i<asiz;i++){
        vector<int> pi=getpi(a);

        for(int j=0;j<(int)a.size();j++){
            if(max<pi[j])max=pi[j];
        }
        a.erase(a.begin());
    }
    printf("%d",max);
}