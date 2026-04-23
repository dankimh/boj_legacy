#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(vector<int> a){
    int asiz=(int)a.size();
    int i,j=0;
    vector<int> ans(asiz,0);
    for(i=1;i<asiz;i++){
        while(j>0&&a[i]!=a[j])j=ans[j-1];
        if(a[i]==a[j]){
            ans[i]=j+1;
            j++;
        }
    }
    return ans;
}
int main(){
    int n,i;
    scanf("%d",&n);
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> sa,sb;
    for(i=n-1;i>0;i--){
        sa.push_back(a[i]-a[i-1]);
        sb.push_back(b[i]-b[i-1]);
    }
    sa.push_back(a[0]-a[n-1]+360000);
    vector<int> ssa=sa;
    ssa.insert(ssa.end(),sa.begin(),sa.end());
    sb.push_back(b[0]-b[n-1]+360000);
    vector<int> pib=getpi(sb);
    int j=0;
    int ch=0;
    for(i=1;i<2*n;i++){
        while(j>0&&ssa[i]!=sb[j])j=pib[j-1];
        if(ssa[i]==sb[j]){
            if(j==n-1){
                ch=1;
                break;
            }
            else j++;
        }
    }
    if(ch)printf("possible");
    else printf("impossible");
}