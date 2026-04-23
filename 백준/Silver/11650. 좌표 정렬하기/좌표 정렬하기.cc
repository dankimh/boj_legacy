#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    pair<int,int> p[100000];
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&p[i].first,&p[i].second);
    }
    sort(p,p+n);
    for(i=0;i<n;i++){
        printf("%d %d\n",p[i].first,p[i].second);
    }
}
