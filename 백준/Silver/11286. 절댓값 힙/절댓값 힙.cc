#include<stdio.h>
#include<queue>
#include<utility>
#define abs(a) a>0?a:-a
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a==0){
            if(q.empty())printf("0\n");
            else{
                printf("%d\n",q.top().second);
                q.pop();
            }
        }
        else q.push({abs(a),a});
    }
}