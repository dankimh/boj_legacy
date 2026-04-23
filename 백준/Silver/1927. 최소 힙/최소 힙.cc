#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int>> q;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a==0){
            if(q.empty())printf("0\n");
            else{
                printf("%d\n",q.top());
                q.pop();
            }
        }
        else q.push(a);
    }
}