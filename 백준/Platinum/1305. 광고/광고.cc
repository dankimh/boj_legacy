#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string a;
    cin>>a;
    int s=(int)a.size();
    int i,j=0;
    vector<int> ans(s,0);
    for(i=1;i<n;i++){
        while(j>0&&a[i]!=a[j]){
            j=ans[j-1];
        }
        if(a[i]==a[j]){
            ans[i]=j+1;
            j++;
        }
    }
    printf("%d",s-ans[s-1]);
}
