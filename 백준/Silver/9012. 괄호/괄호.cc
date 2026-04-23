#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
stack<char> a;
int main(){
    int n,i,j;
    char b[50];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",b);
        for(j=0;j<strlen(b);j++){
            if(b[j]=='(')a.push(b[i]);
            else{
                if(a.empty()){a.push('a');break;}
                else a.pop();
            }
        }
        if(a.empty())printf("YES\n");
        else{
            printf("NO\n");
            while(!a.empty())a.pop();
        }
    }
}
