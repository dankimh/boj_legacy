#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,a,b,j,k,ch=0;
    scanf("%d %d",&n,&a);
    stack<int> s;
    vector<char> ans;
    for(k=1;k<=a;k++){s.push(k);ans.push_back('+');}
    s.pop();ans.push_back('-');
    for(i=1;i<n;i++){
        scanf("%d",&a);
        int top;
        if(s.size()==0)top=-1;
        else top=s.top();
        if(a==top){
            s.pop();
            ans.push_back('-');
        }
        else if(a>top){
            for(;k<=a;k++){s.push(k);ans.push_back('+');}
            s.pop();
            ans.push_back('-');
        }
        else{
            ch=1;
        }
    }
    if(ch)printf("NO");
    else for(auto &i:ans)printf("%c\n",i);
}