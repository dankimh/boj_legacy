#include<queue>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    while(q.size()>1){
        int a;
        q.pop();
        a=q.front();
        q.pop();
        q.push(a);
    }
    printf("%d",q.back());
}