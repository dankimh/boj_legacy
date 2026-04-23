#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> big;
    int mid;
    int n;
    scanf("%d",&n);
    int i,a;
    scanf("%d",&mid);
    printf("%d\n",mid);
    for(i=1;i<n;i++){
        scanf("%d",&a);
        if(a>mid)big.push(a);
        if(a<=mid)small.push(a);
        if(small.size()==big.size()+1){
            big.push(mid);
            mid=small.top();
            small.pop();
        }
        else if(small.size()==big.size()+2){
            big.push(mid);
            mid=small.top();
            small.pop();
        }
        else if(small.size()+2==big.size()){
            small.push(mid);
            mid=big.top();
            big.pop();
        }
        printf("%d\n",mid);
    }
}