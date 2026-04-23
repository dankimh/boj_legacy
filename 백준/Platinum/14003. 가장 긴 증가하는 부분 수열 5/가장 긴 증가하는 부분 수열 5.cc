#include<stdio.h>
#include<vector>
using namespace std;
vector<int> lcs, ind;
int main(){
    int n,a[1000000],i,ch[1000000],cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ch[0]++;
    lcs.push_back(a[0]);
    ch[0]=0;
    for(i=1;i<n;i++){
        if(lcs[cnt]<a[i]){
            lcs.push_back(a[i]);
            cnt++;
            ch[i]=cnt;
        }
        else{
            auto p=lower_bound(lcs.begin(),lcs.end(),a[i])-lcs.begin();
            lcs[p]=a[i];
            ch[i]=p;
        }
    }
    printf("%d\n",cnt+1);
    for(i=n-1;i>=0&&cnt>=0;i--){
        if(ch[i]==cnt){
            ind.push_back(a[i]);
            cnt--;
        }
    }
    for(i=ind.size()-1;i>=0;i--){
        printf("%d ",ind[i]);
    }
}