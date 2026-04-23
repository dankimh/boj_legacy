#include<stdio.h>
#include<queue>
#include<vector>
#define uint long long
using namespace std;
int main(){
    uint k,n,a[100];
    scanf("%lld %lld",&k,&n);
    uint i,j;
    for(i=0;i<k;i++)scanf("%lld",&a[i]);
    vector<uint> ans;
    priority_queue<uint,vector<uint>,greater<uint>> q[100];
    for(i=0;i<k;i++){
        q[i].push(a[i]);
    }
    uint index=0;
    ans.push_back(a[0]);
    index++;
    for(i=0;;i++){
        if(ans.size()==n)break;
        uint min=2147483649,where=0;
        for(j=0;j<index;j++){
            if(min>(a[j]*q[j].top())){
                min=a[j]*q[j].top();
                where=j;
            }
        }
        if(min>a[index]&&index<k){
            min=a[index];
            where=index;
            index++;
        }
        for(j=0;j<=where;j++){
            q[j].push(min);
        }
        q[where].pop();
        ans.push_back(min);
    }
    printf("%lld",ans[n-1]);
}