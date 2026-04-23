#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
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
    int n,i,j=0;
    scanf("%d",&n);
    string meat,now;
    for(i=0;i<n;i++){
        char a;
        cin>>a;
        meat+=a;
    }
    for(i=0;i<n;i++){
        char a;
        cin>>a;
        now+=a;
    }
    now+=now;
    now.erase(now.end()-1);
    vector<int> pi=getpi(now);
    int ans=0;
    for(i=0;i<2*n;i++){
        while(j>0&&now[i]!=meat[j])j=pi[j-1];
        if(now[i]==meat[j]){
            if(j==n-1){
                ans++;
                j=pi[j];
            }
            else j++;
        }
    }
    int g=gcd(ans,n);
    printf("%d/%d",ans/g,n/g);
}
