#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    queue<int> a;
    vector<int> ans;
    int i;
    for(i=0;i<n;i++)a.push(i+1);
    while(!a.empty()){
        if(a.size()>=k){
            int b[k];
            for(i=0;i<k;i++){
                b[i]=a.front();
                a.pop();
            }
            ans.push_back(b[k-1]);
            //printf("%d, ",b[k-1]);
            for(i=0;i<k-1;i++){
                a.push(b[i]);
            }
        }
        else if(a.size()>1){
            int b=k;
            while(b>a.size())b-=a.size();
            int c[b];
            for(i=0;i<b;i++){
                c[i]=a.front();
                a.pop();
            }
            ans.push_back(c[b-1]);
            //printf("%d, ",c[b-1]);
            for(i=0;i<b-1;i++){
                a.push(c[i]);
            }
        }
        else{
            ans.push_back(a.front());
            //printf("%d>",a.front());
            a.pop();
        }
    }
    printf("<");
    for(i=0;i<ans.size()-1;i++){
        printf("%d, ",ans[i]);
    }
    printf("%d>",ans[ans.size()-1]);
}